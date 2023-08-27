#include <iostream>
#include "sim_func.h"
#include <iostream>
#include <xtensor/xrandom.hpp>
#include <xtensor/xio.hpp>
#include <cmath>
#include <xtensor/xmath.hpp>
#include <vector>
#include <xtensor/xadapt.hpp>
#include <tuple>
#include <xtensor/xoperation.hpp>
//#include <xtensor/xmath.hpp>

SimFunc::SimFunc() 
{

}

void SimFunc::say_hello()
{
	std::cout << "Hello from SimFunc" << std::endl;
}

xt::xarray<double> SimFunc::sim_GBM(int n, float mu, float sigma, float dt, float S0)
{
	xt::xarray<double> z = xt::random::randn<double>({ n },0.0, 1.0);
	xt::xarray<double> St_inc = xt::exp((mu - sigma*sigma/2)*dt +  sigma * std::sqrt(dt)* z);
	xt::xarray<double> S0_arr = {S0};
	xt::xarray<double> St_arr = xt::concatenate(xt::xtuple(S0_arr, St_inc));
	xt::xarray<double> S_path = xt::cumprod(St_arr);	
	return S_path;
}

xt::xarray<double> SimFunc::sim_possion_arrival(float max_time, float lambda)
{
	assert(max_time > 0);
	std::vector<double> arr_times;
	double curr_time = 0;
	while (curr_time < max_time) {
		curr_time = curr_time + xt::random::exponential({ 1 }, lambda).at(0);
		arr_times.push_back(curr_time);
	}
	arr_times.pop_back();
	xt::xarray<double> res = xt::adapt(arr_times);
	return res;
}

std::tuple<xt::xarray<double>, xt::xarray<double>> SimFunc::sim_merton_jumps(float max_time, float mu, float sigma, float lambda)
{
	xt::xarray<double> arrival_times = sim_possion_arrival(max_time, lambda);
	int n = arrival_times.size();
	xt::xarray<double> jump_sizes = xt::random::randn<double>({ n }, mu, sigma);
	xt::xarray<double> process_values = xt::cumsum(jump_sizes);
	return std::make_tuple(arrival_times, process_values);
}

xt::xarray<double> SimFunc::get_values_of_jump_process(int n, float dt, xt::xarray<double> arrival_times, xt::xarray<double> process_values)
{
	
	xt::xarray<double> res = xt::zeros<double>({ n + 1 });
	for (int i = 1; i <= n; i++) {
		float curr_time = i * dt;
		auto v = xt::filter(process_values, arrival_times <= curr_time);
		double last_value = 0;
		if (v.size()) {
			last_value = v(v.size()-1);
		}
		res(i) = last_value;
	}
	return res;
}

xt::xarray<double> SimFunc::sim_merton_GBM(int n, float mu, float sigma, float lambda, float jump_mu, float jump_sigma, float dt, float S0)
{
	float max_time = n * dt;
	std::tuple<xt::xarray<double>, xt::xarray<double>> merton_process = sim_merton_jumps(max_time, jump_mu, jump_sigma, lambda);
	xt::xarray<double> merton_arrivals = std::get<0>(merton_process);
	xt::xarray<double> merton_values = std::get<1>(merton_process);
	xt::xarray<double> merton_values_reindex = get_values_of_jump_process(n, dt, merton_arrivals, merton_values);
	xt::xarray<double> gbm = sim_GBM(n, mu, sigma, dt, S0);
	xt::xarray<double> jump_gbm = gbm * xt::exp(merton_values_reindex);
	return jump_gbm;
}


std::tuple<xt::xarray<double>, xt::xarray<double>> SimFunc::sim_kou_jumps(float max_time, float lambda_arrival, float p_pos_jump, float lambda_pos, float lambda_neg)
{
	assert((p_pos_jump < 1) && (p_pos_jump > 0));
	xt::xarray<double> arrival_times = sim_possion_arrival(max_time, lambda_arrival);
	int n = arrival_times.size();
	xt::xarray<double> pos_jumps = xt::random::exponential<double>({ n }, lambda_pos);
	xt::xarray<double> neg_jumps = -xt::random::exponential<double>({ n }, lambda_neg);
	xt::xarray<int> jump_sides = xt::random::binomial<int>({ n }, 1, p_pos_jump);
	xt::xarray<double> jump_sizes = xt::where(jump_sides > 0, pos_jumps, neg_jumps);

	xt::xarray<double> process_values = xt::cumsum(jump_sizes);
	return std::make_tuple(arrival_times, process_values);
}

xt::xarray<double> SimFunc::sim_kou_GBM(int n, float mu, float sigma, float lambda_arrival, float p_pos_jump, float lambda_pos, float lambda_neg, float dt, float S0)
{
	float max_time = n * dt;
	std::tuple<xt::xarray<double>, xt::xarray<double>> kou_process = sim_kou_jumps(max_time,  lambda_arrival, p_pos_jump, lambda_pos, lambda_neg);
	xt::xarray<double> kou_arrivals = std::get<0>(kou_process);
	xt::xarray<double> kou_values = std::get<1>(kou_process);
	xt::xarray<double> kou_values_reindex = get_values_of_jump_process(n, dt, kou_arrivals, kou_values);
	xt::xarray<double> gbm = sim_GBM(n, mu, sigma, dt, S0);
	xt::xarray<double> jump_gbm = gbm * xt::exp(kou_values_reindex);
	return jump_gbm;
}

xt::xarray<double> SimFunc::sim_Gamma(int n, float a, float b, float dt)
{	
	assert(a > 0);
	assert(b > 0);
	assert(dt > 0);
	xt::xarray<double> g = xt::random::gamma<double>({ n }, a * dt, 1 / b);
	xt::xarray<double> G0_arr = { 0 };
	xt::xarray<double> Gt_arr = xt::concatenate(xt::xtuple(G0_arr, g));
	xt::xarray<double> G_path = xt::cumsum(Gt_arr);
	return G_path;
}

xt::xarray<double> SimFunc::sim_VG(int n, float sigma, float nu, float theta, float dt)
{
	
	float mu_p = std::sqrt(theta * theta + 2 * sigma * sigma / nu) / 2 + theta / 2;
	float mu_q = std::sqrt(theta * theta + 2 * sigma * sigma / nu) / 2 - theta / 2;
		
	float a_p = mu_p;
	float b_p = mu_p*mu_p*nu;
	xt::xarray<double> g_plus = sim_Gamma(n, a_p, b_p, dt);

	float a_m = mu_q;
	float b_m = mu_q * mu_q * nu;
	xt::xarray<double> g_minus = sim_Gamma(n, a_m, b_m, dt);
	
	xt::xarray<double> G_path = g_plus - g_minus;

	return G_path;
}

xt::xarray<double> SimFunc::sim_BM(xt::xarray<double> times)
{
	xt::xarray<double> time0 = { 0 };
	xt::xarray<double> extend_times = xt::concatenate(xt::xtuple(time0, times));
	
	xt::xarray<double> time_inc = xt::diff(extend_times);
	xt::xarray<double> z = xt::random::randn<double>({ times.size()}, 0.0, 1.0);
	xt::xarray<double> bm_inc = xt::sqrt(time_inc) * z;
	xt::xarray<double> bm = xt::cumsum(bm_inc);
	return bm;
}

xt::xarray<double> SimFunc::sim_IG_rv(int n, float a, float b)
{
	xt::xarray<double> v = xt::random::randn<double>({ n }, 0.0, 1.0);
	xt::xarray<double> y = xt::pow(v, 2);
	xt::xarray<double> x = (a / b) + y / (2 * b * b) - xt::sqrt(4 * a * b * y + xt::pow(y, 2)) / (2 * b * b);
	xt::xarray<double> u = xt::random::rand<double>({ n }, 0, 1);
	xt::xarray<double> c = a / (a + x * b);
	xt::xarray<double> x_alt = (a * a) / (b * b * x);
	xt::xarray<double> ig = xt::where(u <= c, x, x_alt);
	return ig;
}

xt::xarray<double> SimFunc::sim_IG(int n, float a, float b, float dt)
{
	xt::xarray<double> i_arr = sim_IG_rv(n, a, b);
	xt::xarray<double> ig0 = { 0 };
	xt::xarray<double> ig_inc = xt::concatenate(xt::xtuple(ig0, i_arr));
	xt::xarray<double> ig = xt::cumsum(ig_inc);
	return ig;
}

xt::xarray<double> SimFunc::sim_NIG(int n, float alpha, float beta, float delta, float dt)
{
	assert(alpha > 0);
	assert((beta < alpha) && (beta > -alpha));
	assert(delta > 0);
	float a = 1;
	float b = delta * std::sqrt(alpha*alpha - beta*beta);

	xt::xarray<double> ig = sim_IG(n, a, b, dt);
	xt::xarray<double> W = sim_BM(ig);
	xt::xarray<double> nig = beta * delta * delta * ig + delta * W;
	return nig;
}