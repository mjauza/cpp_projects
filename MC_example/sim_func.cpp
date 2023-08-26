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
		curr_time = xt::random::exponential({ 1 }, lambda).at(0);
		arr_times.push_back(curr_time);
	}
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




