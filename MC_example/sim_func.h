#ifndef SIM_FUNC_H
#define SIM_FUNC_H
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>


class SimFunc
{
	public:
		SimFunc();
		void say_hello();

		static xt::xarray<double> sim_GBM(int n, float mu, float sigma, float dt = 1, float S0 = 1);
		//static xt::xarray<double> sim_possion_arrival(int n, float lambda);
		static xt::xarray<double> sim_possion_arrival(float max_time, float lambda);
		static std::tuple<xt::xarray<double>, xt::xarray<double>> sim_merton_jumps(float max_time, float mu, float sigma, float lambda);
		static xt::xarray<double> get_values_of_jump_process(int n, float dt, xt::xarray<double> arrival_times, xt::xarray<double> process_values);
		static xt::xarray<double> sim_merton_GBM(int n, float mu, float sigma, float lambda, float jump_mu, float jump_sigma, float dt = 1, float S0 = 1);

		static std::tuple<xt::xarray<double>, xt::xarray<double>> sim_kou_jumps(float max_time, float lambda_arrival, float p_pos_jump, float lambda_pos, float lambda_neg);
		static xt::xarray<double> sim_kou_GBM(int n, float mu, float sigma, float lambda_arrival, float p_pos_jump, float lambda_pos, float lambda_neg, float dt = 1, float S0 = 1);
		
		static xt::xarray<double> sim_VG(int n, float sigma, float nu, float theta, float dt = 1);
		static xt::xarray<double> sim_Gamma(int n, float a, float b, float dt = 1);

		static xt::xarray<double> sim_BM(xt::xarray<double> times);
		static xt::xarray<double> sim_IG_rv(int n, float a, float b);

		static xt::xarray<double> sim_IG(int n, float a, float b, float dt = 1);
		
		static xt::xarray<double> sim_NIG(int n, float alpha, float beta, float delta, float dt = 1);

		static xt::xarray<double> sim_GBM_paths(int num_paths, int n, float mu, float sigma, float dt, float S0);
		static xt::xarray<double> sim_merton_GBM_paths(int num_paths, int n, float mu, float sigma, float lambda, float jump_mu, float jump_sigma, float dt, float S0);
		static xt::xarray<double> sim_kou_GBM_paths(int num_paths, int n, float mu, float sigma, float lambda_arrival, float p_pos_jump, float lambda_pos, float lambda_neg, float dt = 1, float S0 = 1);
		
};


#endif
