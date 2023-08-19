#include "ArrExample.h"
#include <iostream>
#include <string>
#include <memory>
ArrExample::ArrExample()
{
    //ctor
}

ArrExample::ArrExample(int n)
{
    this -> data_ptr = std::make_shared<float[]>(n);
    for(int i = 0; i < n; i++){
        data_ptr[i] = i;
        std::cout << std::to_string(data_ptr[i]) << std::endl;
    }
}

void ArrExample::ArrExample::print_data()
{
    //int arrSize = sizeof((this->data_ptr))/sizeof(((this->data_ptr))[0]);
    int arrSize = 20;
    /*
    for(int i = 0; i<arrSize; i++ ){
        std::cout << std::to_string((this->data_ptr)) << std::endl;
    }
    */
    /*
    for (float f : ) {
        std::cout << std::to_string(f) << std::endl;
    }
    */
}

ArrExample::~ArrExample()
{
    //dtor
}
