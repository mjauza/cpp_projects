#include "pricing_fun.h"
#include <iostream>
#include <xtensor/xmath.hpp>
#include <cmath>
#include "sim_func.h"
#include <xtensor/xview.hpp>
#include <xtensor/xio.hpp>
#include <iostream>
#include <complex>
#include <functional>
#include "integral_fun.h"
#include <numbers>

PricingFun::PricingFun() 
{

}


void PricingFun::hello_world()
{
	std::cout << "helllo from PricingFun" << std::endl;
}

double PricingFun::mc_call_price(xt::xarray<double> ST_arr, float r, float K, float T)
{
	xt::xarray<double> payout = xt::maximum(ST_arr - K, 0);
	double price = std::exp(-r*T)*xt::mean(payout)[0];
	return price;
}

double PricingFun::mc_call_price_GBM(int num_paths, float r, float sigma, float T, float K, float S0)
{
	int n = 1;
	float dt = T;
	float mu = r;
	xt::xarray<double> S_paths = SimFunc::sim_GBM_paths(num_paths, n, mu, sigma, dt, S0);
	xt::xarray<double> ST_arr = xt::row(S_paths, 1);
	//std::cout << ST_arr << std::endl;
	double price = mc_call_price(ST_arr, r, K, T);
	return price;
}

double PricingFun::mc_call_price_merton(int num_paths, float r, float sigma, float lambda, float jump_mu, float jump_sigma, float T, float K, float S0)
{
	float k_bar = std::exp(jump_mu + jump_sigma * jump_sigma / 2) - 1;
	float mu = r - lambda * k_bar;
	int n = 1;
	float dt = T;
	static xt::xarray<double> S_paths = SimFunc::sim_merton_GBM_paths(num_paths, n, mu, sigma, lambda, jump_mu, jump_sigma, dt, S0);
	xt::xarray<double> ST_arr = xt::row(S_paths, 1);
	double price = mc_call_price(ST_arr, r, K, T);
	return price;
}

std::complex<double> PricingFun::merton_char_func(std::complex<double> u, double T, double r, double sigma,  double jump_mu, double jump_sigma, double lambda)
{
	std::complex<double> i1(0, 1);
	double eps = std::exp(jump_mu + jump_sigma * jump_sigma / 2.0) - 1;
	double omega = r - sigma * sigma / 2.0 - lambda * eps;
	double alpha = jump_mu;
	std::complex<double> a1 = i1 * u * omega * T - 0.5*u*u* sigma * sigma *T;
	std::complex<double> a2 = i1 * u * alpha - u * u * jump_sigma * jump_sigma / 2.0;
	std::complex<double> res = std::exp(a1 + lambda * T * (std::exp(a2) - 1.0));
	return res;
}

std::function<std::complex<double>(std::complex<double>)> PricingFun::get_merton_char_func(double T, double r, double sigma, double jump_mu, double jump_sigma, double lambda)
{
	auto func = [T, r, sigma, jump_mu, jump_sigma, lambda](std::complex<double> u) {return merton_char_func(u, T, r, sigma, jump_mu, jump_sigma, lambda); };
	return func;
}

double PricingFun::fourier_call_price(std::function<std::complex<double>(std::complex<double>)> char_func, double S0, double T, double r, double K, int n_simps, double x_min, double x_max)
{
	
	double F = S0 * std::exp(r*T);
	double k = std::log(K / F);
	std::function<double(double)> func = [k, &char_func](double u) {
		std::complex<double> i1(0, 1);
		return 1.0 / (u * u + 0.25) * std::real(  std::exp(-i1 * u * k) * char_func(u - i1 / 2.0)  );
		};

	double integral = IntegralFun::simposon(n_simps, x_min, x_max, func);
	double price = std::exp(-r * T) * (F - std::sqrt(F * K) / std::numbers::pi * integral);
	return price;
	
}



std::complex<double> PricingFun::kou_char_func(std::complex<double> u, double r, double sigma, double lambda_arrival, double p_pos_jump, double lambda_pos, double lambda_neg, double T)
{
	//double eps = p_pos_jump * lambda_pos / (lambda_pos - 1.0) + p_pos_jump * lambda_neg / (lambda_neg + 1.0) - 1.0;
	double eps = p_pos_jump * lambda_pos / (lambda_pos - 1.0) + (1.0 - p_pos_jump)*lambda_neg / (lambda_neg + 1.0) - 1.0;
	/*
	double b = r - sigma * sigma / 2.0 - lambda_arrival*eps;
	std::complex<double> i1(0, 1);
	std::complex<double> a1 = i1 * b * u * T - sigma * sigma * u * u * T / 2.0;
	std::complex<double> a2 = i1 * u * lambda_arrival * T * (p_pos_jump / (lambda_pos - i1 * u) + (1 - p_pos_jump) / (lambda_neg + i1 * u));
	std::complex<double> res = std::exp(a1 + a2);
	*/
	double mu = r - lambda_arrival * eps;
	double gamma = mu - sigma * sigma / 2.0;
	std::complex<double> i1(0, 1);
	std::complex<double> a1 = i1 * gamma * u - sigma * sigma * u * u / 2.0;
	std::complex<double> a2 = lambda_arrival * (p_pos_jump * lambda_pos / (lambda_pos - i1 * u) + (1 - p_pos_jump) * lambda_neg / (lambda_neg + i1 * u) - 1.0);
	std::complex<double> res = std::exp(T * (a1 + a2));
	return res;
}

std::function<std::complex<double>(std::complex<double>)> PricingFun::get_kou_char_func(double r, double sigma, double lambda_arrival, double p_pos_jump, double lambda_pos, double lambda_neg, double T)
{
	auto func = [r, sigma, lambda_arrival, p_pos_jump, lambda_pos, lambda_neg, T](std::complex<double> u) {return kou_char_func(u, r, sigma, lambda_arrival, p_pos_jump, lambda_pos, lambda_neg, T); };
	return func;
}

double PricingFun::mc_call_price_kou(int num_paths, float r, float sigma, float lambda_arrival, float p_pos_jump, float lambda_pos, float lambda_neg, float T, float S0, float K)
{
	int n = 1;
	float dt = T;
	double eps = p_pos_jump * lambda_pos / (lambda_pos - 1.0) + (1.0 - p_pos_jump) * lambda_neg / (lambda_neg + 1.0) - 1.0;
	float mu = r - lambda_arrival*eps;

	xt::xarray<double> S_paths = SimFunc::sim_kou_GBM_paths(num_paths, n, mu, sigma, lambda_arrival, p_pos_jump, lambda_pos, lambda_neg, dt, S0);

	xt::xarray<double> ST_arr = xt::row(S_paths, 1);
	double price = mc_call_price(ST_arr, r, K, T);
	return price;


}






