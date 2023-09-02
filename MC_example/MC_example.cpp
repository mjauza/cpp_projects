﻿#include "MC_example.h"
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include "sim_func.h"
#include "pricing_fun.h"
#include "integral_fun.h"
#include <functional>
#include <cmath>
using namespace std;

void test_merton();
void test_integration();

int main()
{
    
    test_integration();
    //test_merton();
    
    return 0;
}

void test_integration()
{
    /*
    double res = IntegralFun::simposon(5, &IntegralFun::test_fun);
    std::cout << "Itegration res: " << res << std::endl;
    */

    std::function<double(double)> int_fun = IntegralFun::get_test_fun(1.0, 1.0, 1.0);
    //std:cout << int_fun(1) << std::endl;
    //std::cout << int_fun(2) << std::endl;
    //double res = IntegralFun::simposon(6,0,2,int_fun);
    auto sin_fun = [](double x) {return std::sin(x); };
    auto sin_integral = [](double x) {return -std::cos(x); };
    double res_num = IntegralFun::simposon(std::pow(2,8), 0, 6, sin_fun);
    double res_ana = sin_integral(6) - sin_integral(0);
    
    std::cout << "sin num integral: " << res_num << std::endl;
    std::cout << "sin ana integral: " << res_ana << std::endl;

}

void test_merton()
{
    int num_paths = 10000;
    float r = 0.03;
    float sigma = 0.1;
    float lambda = 1;
    float jump_mu = 0;
    float jump_sigma = 0.2;
    float T = 1;
    float K = 80;
    float S0 = 100;
    double mc_merton = PricingFun::mc_call_price_merton(num_paths, r, sigma, lambda, jump_mu, jump_sigma, T, K, S0);
    std::cout << "MC Call Merton price: " << mc_merton << std::endl;
}