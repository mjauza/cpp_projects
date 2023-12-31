#ifndef PRICING_FUN_H
#define PRICING_FUN_H
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <functional>

class PricingFun
{
	public:
		PricingFun();
		void hello_world();

		static double mc_call_price(xt::xarray<double> ST_arr, float r, float K, float T);
		static double mc_call_price_GBM(int num_paths, float r, float sigma, float T, float K, float S0);
		static double mc_call_price_merton(int num_paths, float r, float sigma, float lambda, float jump_mu, float jump_sigma, float T, float K, float S0);

		static std::complex<double> merton_char_func(std::complex<double> u, double T, double r, double sigma, double jump_mu, double jump_sigma, double lambda);

		static std::function<std::complex<double>(std::complex<double>)> get_merton_char_func(double T, double r, double sigma, double jump_mu, double jump_sigma, double lambda);

		static double fourier_call_price(std::function<std::complex<double>(std::complex<double>)> char_func, double S0, double T, double r, double K, int n_simps, double x_min, double x_max);

		static std::complex<double> kou_char_func(std::complex<double> u, double r, double sigma, double lambda_arrival, double p_pos_jump, double lambda_pos, double lambda_neg, double T);
		static std::function<std::complex<double>(std::complex<double>)> get_kou_char_func(double r, double sigma, double lambda_arrival, double p_pos_jump, double lambda_pos, double lambda_neg, double T);

		static double mc_call_price_kou(int num_paths, float r, float sigma, float lambda_arrival, float p_pos_jump, float lambda_pos, float lambda_neg, float T, float S0, float K);
};


#endif