#include "BM.h"
#include <random>
#include <cmath>
#include <array>
BM::BM()
{
    //ctor
}

std::shared_ptr<float[]> BM::generate_standard_BM(int n_timestamp, float dt)
{
    std::shared_ptr<float[]> bm_path(new float[n_timestamp+1]);
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0,1);
    bm_path[0] = 0;
    for(int i= 1; i<n_timestamp+1; i++){
        float dW = std::sqrt(dt) * distribution(generator);
        bm_path[i] = bm_path[i-1] + dW;
    }
    return bm_path;
}

std::vector<float> BM::generate_GBM(int n_timestamp, float mu, float sigma, float S0, float dt)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0,1);
    std::vector<float> gmb;
    gmb.push_back(S0);
    for(int i=1; i<n_timestamp+1; i++){
        float Z = distribution(generator);
        float St = gmb.back();
        float dS = St*(mu - sigma*sigma/2)*dt + St * sigma * std::sqrt(dt) * Z;
        float St1 = St+ dS;
        gmb.push_back(St1);
    }
    return gmb;
}

BM::~BM()
{
    //dtor
}
