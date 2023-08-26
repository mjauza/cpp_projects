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
    
    std::tuple<xt::xarray<double>, xt::xarray<double>> merton_process = SimFunc::sim_merton_jumps(10, 0, 1, 1);
    xt::xarray<double> merton_arrivals = std::get<0>(merton_process);
    xt::xarray<double> merton_values = std::get<1>(merton_process);

    cout << "Merton arrivals: " << merton_arrivals << endl;
    cout << "Merton values: " << merton_values << endl;
    return 0;
}
