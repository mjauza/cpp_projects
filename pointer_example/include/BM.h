#ifndef BM_H
#define BM_H
#include <memory>
#include <array>
#include <vector>
class BM
{
    public:
        BM();
        static std::shared_ptr<float[]> generate_standard_BM(int n_timesramp, float dt);
        virtual ~BM();
        static std::vector<float> generate_GBM(int n_timestamp, float mu, float sigma, float S0, float dt);

    protected:

    private:
};

#endif // BM_H
