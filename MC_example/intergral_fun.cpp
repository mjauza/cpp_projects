#include "integral_fun.h"
#include <iostream>
#include <cassert>

IntegralFun::IntegralFun()
{

}

void IntegralFun::hello_world()
{
	std::cout << "Hello from IntegralFun" << std::endl;
}

double IntegralFun::simposon(int n, double x_min, double x_max, std::function<double(double)> func)
{
	assert(x_max > x_min);
	double res = 0;
	double h = (x_max - x_min) / (double)n;	
	for (int i_mid = 1; i_mid <= (n - 1); i_mid += 2) {
		double x_i = i_mid * h + x_min;
		double x_m1 = x_i - h;		
		double x_p1 = x_i + h;
		double Pi = (h / 3.0) * (func(x_m1) + 4.0 * func(x_i) + func(x_p1));
		res += Pi;		
	}
	return res;

}

std::function<double(double)> IntegralFun::get_test_fun(double theta, double mu, double sigma)
{
	auto fun = [theta, mu, sigma](double x) -> double {
		return (x * theta * mu * sigma);
		};
	return fun;
}
double IntegralFun::test_fun(double x)
{
	return x;
}