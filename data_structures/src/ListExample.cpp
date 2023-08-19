#include "ListExample.h"
#include <iostream>
#include <string>
bool ListExample::sort_desc(const float &first, const float& second)
{
    return first > second;
}
ListExample::ListExample()
{
    //ctor
}

ListExample::ListExample(int n)
{
    for(int i = 1; i<=n; i++){
        this ->even.push_back(i*2);
        this->odd.push_back(i*2 - 1);
    }
    this->odd.sort(this->sort_desc);
}



void ListExample::print_data()
{
    std::cout << "Evens:" << std::endl;
    for(float f : this->even){
        std::cout << std::to_string(f) << std::endl;
    }

    std::cout << "Odds:" << std::endl;
    for(float f : this->odd){
        std::cout << std::to_string(f) << std::endl;
    }
}


ListExample::~ListExample()
{
    //dtor
}
