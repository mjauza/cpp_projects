#include "pricing_fun.h"
#include <iostream>
#include <xtensor/xmath.hpp>
#include <cmath>
#include "sim_func.h"
#include <xtensor/xview.hpp>
#include <xtensor/xio.hpp>
#include <iostream>
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
