#ifndef PRICING_FUN_H
#define PRICING_FUN_H
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>

class PricingFun
{
	public:
		PricingFun();
		void hello_world();

		static double mc_call_price(xt::xarray<double> ST_arr, float r, float K, float T);
		static double mc_call_price_GBM(int num_paths, float r, float sigma, float T, float K, float S0);
		static double mc_call_price_merton(int num_paths, float r, float sigma, float lambda, float jump_mu, float jump_sigma, float T, float K, float S0);

};


#endif