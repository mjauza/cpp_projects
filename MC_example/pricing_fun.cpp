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

std::complex<double> PricingFun::merton_char_func(std::complex<double> u, double T, double r, double jump_mu, double jump_sigma, double lambda)
{
	std::complex<double> i1(0, 1);
	double eps = std::exp(jump_mu + jump_sigma * jump_sigma / 2.0) - 1;
	double omega = r - jump_sigma * jump_sigma / 2.0 - lambda * eps;
	double alpha = jump_mu;
	std::complex<double> a1 = i1 * u * omega * T - 0.5*u*u*jump_sigma*jump_sigma*T;
	std::complex<double> a2 = i1 * u * alpha - u * u * jump_sigma * jump_sigma / 2.0;
	std::complex<double> res = std::exp(a1 + lambda * T * (std::exp(a2) - 1.0));
	return res;
}

std::function<std::complex<double>(std::complex<double>)> PricingFun::get_merton_char_func(double T, double r, double jump_mu, double jump_sigma, double lambda)
{
	auto func = [T, r, jump_mu, jump_sigma, lambda](std::complex<double> u) {return merton_char_func(u, T, r, jump_mu, jump_sigma, lambda); };
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





