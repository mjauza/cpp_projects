#include "MC_example.h"
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include "sim_func.h"
#include "pricing_fun.h"
#include "integral_fun.h"
#include <functional>
#include <cmath>
#include <complex>
using namespace std;

void test_merton();
void test_merton_char();
void test_integration();
void test_kou();
int main()
{
    
    //test_merton_char();
    //test_integration();
    //test_merton();
    test_kou();
    
    return 0;
}


void test_merton_char()
{
    double u = 1;
    double T = 1;
    double r = 0.03;
    double jump_mu = 0; 
    double jump_sigma = 0.1;
    double sigma = 0.1;
    double lambda = 1;
    double S0 = 100;
    double K = 80;
    int n_simps = std::pow(2, 8);
    double x_min = 0.000001;
    double x_max = std::pow(2, 4);

    
    std::complex<double> merton_char = PricingFun::merton_char_func(u, T, r, sigma, jump_mu, jump_sigma, lambda);    
    std::function<std::complex<double>(std::complex<double>)> merton_func = PricingFun::get_merton_char_func(T, r, sigma,  jump_mu, jump_sigma, lambda);
    
    double call_price = PricingFun::fourier_call_price(merton_func, S0, T, r, K, n_simps, x_min, x_max);
    std::cout << "Call price with fourier: " << call_price << std::endl;

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

    std::function<std::complex<double>(std::complex<double>)> merton_func = PricingFun::get_merton_char_func(T, r, sigma, jump_mu, jump_sigma, lambda);
    int n_simps = std::pow(2, 17);
    double x_min = 0.0000001;
    double x_max = 200;
    double call_price = PricingFun::fourier_call_price(merton_func, S0, T, r, K, n_simps, x_min, x_max);
    std::cout << "Fourier Call Merton price: " << call_price << std::endl;
}

void test_kou()
{   
    double r = 0.03;
    double sigma = 0.1;
    double lambda_arrival = 2;
    double p_pos_jump = 0.5;
    double lambda_pos = 2; 
    double lambda_neg = 2; 
    double T = 1;
    double S0 = 100;
    double K = 80;

    std::function<std::complex<double>(std::complex<double>)> kou_char_func = PricingFun::get_kou_char_func(r, sigma, lambda_arrival, p_pos_jump, lambda_pos, lambda_neg, T);
    int n_simps = std::pow(2, 18);
    double x_min = 0.0000001;
    double x_max = 1000;
    double call_price = PricingFun::fourier_call_price(kou_char_func, S0, T, r, K, n_simps, x_min, x_max);

    std::cout << "Fourier Call Kou price: " << call_price << std::endl;

    int num_paths = 10000;
    double mc_call_price = PricingFun::mc_call_price_kou(num_paths, r, sigma, lambda_arrival, p_pos_jump, lambda_pos, lambda_neg, T, S0, K);
    std::cout << "MC Call Kou price: " << mc_call_price << std::endl;

}