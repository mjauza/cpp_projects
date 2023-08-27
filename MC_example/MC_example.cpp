#include "MC_example.h"
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include "sim_func.h"
using namespace std;

int main()
{
    
    SimFunc sf = SimFunc();
    sf.say_hello();

    // xt::xarray<double> S_arr = SimFunc::sim_GBM(10, 0.05, 0.2);
    // std::cout << S_arr << std::endl;

    //xt::xarray<double> N_arrival = SimFunc::sim_possion_arrival(10, 1);
    //cout << N_arrival << endl;
    
    /*
    std::tuple<xt::xarray<double>, xt::xarray<double>> merton_process = SimFunc::sim_merton_jumps(10, 0, 1, 1);
    xt::xarray<double> merton_arrivals = std::get<0>(merton_process);
    xt::xarray<double> merton_values = std::get<1>(merton_process);
    cout << "Merton arrivals: " << merton_arrivals << endl;
    cout << "Merton values: " << merton_values << endl;
    */

    /*
    xt::xarray<double> merton_gbm = SimFunc::sim_merton_GBM(10, 0.05, 0.2, 1, 0, 1);
    cout << "Merton GBM: " << merton_gbm << endl;
    */
    
    /*
    std::tuple<xt::xarray<double>, xt::xarray<double>> kou_process = SimFunc::sim_kou_jumps(10, 1, 0.5, 1, 1);
    xt::xarray<double> kou_arrivals = std::get<0>(kou_process);
    xt::xarray<double> kou_values = std::get<1>(kou_process);
    std::cout << "Kou arrivals: " << kou_arrivals << std::endl;
    std::cout << "Kou values: " << kou_values << std::endl;
    */
    
    /*
    xt::xarray<double> kou_gbm = SimFunc::sim_kou_GBM(10, 0.05, 0.2, 1, 0.5, 1, 1);
    std::cout << "Kou GBM: " << kou_gbm << std::endl;
    */

    /*
    xt::xarray<double> vg = SimFunc::sim_VG(10, 10, 10, 10);
    std::cout << "VG: " << vg << std::endl;
    */

    /*
    xt::xarray<double> times = {1, 2, 3};
    xt::xarray<double> bm_at_times = SimFunc::sim_BM(times);
    std::cout << "BM at times: " << bm_at_times << std::endl;
    */

    /*
    xt::xarray<double> ig_rvs = SimFunc::sim_IG_rv(10, 1, 1);
    std::cout << "IG rvs: " << ig_rvs << std::endl;
    */

    /*
    xt::xarray<double> ig = SimFunc::sim_IG(10, 1, 1, 1);
    std::cout << "IG process: " << ig << std::endl;
    */

    xt::xarray<double> nig = SimFunc::sim_NIG(10, 2, 1, 1);
    std::cout << "NIG process: " << nig << std::endl;
    
    return 0;
}
