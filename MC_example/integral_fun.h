#ifndef INTEGRAL_FUN_H
#define INTEGRAL_FUN_H
#include <functional>

class IntegralFun
{
	public:
		IntegralFun();
		void hello_world();
		static double simposon(int n, double x_min, double x_max, std::function<double(double)> func);
		static double test_fun(double x);
		static std::function<double(double)> get_test_fun(double theta, double mu, double sigma);

};

#endif