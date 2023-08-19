#ifndef VECEXAMPLE_H
#define VECEXAMPLE_H
#include <vector>

class VecExample
{
    public:
        VecExample();
        VecExample(int n);
        void print_data();
        std::vector<int> get_data();
        std::vector<float> add_to_data(std::vector<float> add_data);
        virtual ~VecExample();

    protected:
        std::vector<int> data;

    private:
};

#endif // VECEXAMPLE_H
