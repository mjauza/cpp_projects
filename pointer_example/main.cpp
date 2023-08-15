#include <iostream>
#include "Rectangle.h"
#include <string>
#include <memory>
#include <BM.h>
#include <algorithm>
#include <vector>
using namespace std;

void rectangle_example();
void bm_example();
void gbm_example();
int main()
{
    //bm_example();
    gbm_example();
    return 0;
}

void bm_example()
{
    int n_timestamp = 20;
    std::shared_ptr<float[]> bm_ptr = BM::generate_standard_BM(n_timestamp, 0.1);

    for(int i = 0; i < n_timestamp+1; i++){
        std::cout << std::to_string(i) << ": " << std::to_string(bm_ptr[i]) << std::endl;
    }
}

void gbm_example()
{
    std::vector<float> gbm = BM::generate_GBM(20, 0, 0.1, 1, 0.1);
    for (auto it = gbm.begin(); it != gbm.end(); it++){
        std::cout << *it << std::endl;
    }


}


void rectangle_example()
{
    auto_ptr<Rectangle> P_rct(new Rectangle(3,2));
    std::cout << "Rectangle " << P_rct->to_string() << " has area " << std::to_string(P_rct->get_area()) << std::endl;
}
