#ifndef ARREXAMPLE_H
#define ARREXAMPLE_H
#include <memory>

class ArrExample
{
    public:
        ArrExample();
        ArrExample(int n);
        void print_data();
        virtual ~ArrExample();

    protected:
        std::shared_ptr<float[]> data_ptr;

    private:
};

#endif // ARREXAMPLE_H
