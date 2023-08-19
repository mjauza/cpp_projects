#include "VecExample.h"
#include <iostream>
#include <stdexcept>

VecExample::VecExample()
{
    //ctor
}

VecExample::VecExample(int n)
{
    for(int i = 0; i < n; i++){
        (this -> data).push_back(i);
    }
}

void VecExample::print_data()
{
    for( auto it = (this->data).begin(); it != (this->data).end(); it++){
        std::cout << *it << std::endl;
    }
}

std::vector<int> VecExample::get_data()
{
    return this->data;
}

std::vector<float> VecExample::add_to_data(std::vector<float> add_data)
{
    int s1 = this->data.size();
    int s2 = add_data.size();
    if (s1 != s2){
        throw std::invalid_argument( "add_data and data not of same size" );
    }
    std::vector<float> new_data;
    for(int i = 0; i < s1; i++){
        float d = add_data.at(i) + (this->data).at(i);
        new_data.push_back(d);
    }
    return new_data;
}

VecExample::~VecExample()
{
    //dtor
}
