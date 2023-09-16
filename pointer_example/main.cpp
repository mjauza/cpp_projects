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
void rect_exmaple();
void unique_ptr_example();
void use_ptr(std::unique_ptr<Rectangle> &ptr);
int main()
{
    //bm_example();
    //gbm_example();
    //rect_exmaple();
    unique_ptr_example();
    return 0;
}

void use_ptr(std::unique_ptr<Rectangle> &ptr)
{
    std::cout << "this is use_ptr function: " << ptr -> to_string() << std::endl;

}

void unique_ptr_example()
{
    Rectangle r1 = Rectangle(2,3);
    std::unique_ptr<Rectangle> ptr1 = make_unique<Rectangle>(2,3);
    auto ptr2 = make_unique<Rectangle>(3,3);

    std::cout << "Before function: " << std::endl;
    std::cout << "ptr1 : " << ptr1->to_string() << "; area: " << ptr1->get_area() << std::endl;
    use_ptr(ptr1);
    std::cout << "After function: " << std::endl;
    std::cout << "ptr1 : " << ptr1->to_string() << "; area: " << ptr1->get_area() << std::endl;
}

void rect_exmaple()
{
    int N = 10;
    auto ptr  =std::make_unique<Rectangle[]>(N);
    for(int i = 1; i<=N; i++ ){
        ptr[i-1] = ( Rectangle(i,i));
    }
    for(int i = 1; i<=N; i++ ){
        std::cout << ptr[i-1].to_string() << "; area = " << ptr[i-1].get_area() << std::endl;
    }
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
