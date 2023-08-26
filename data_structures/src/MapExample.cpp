#include "MapExample.h"
#include <iostream>
MapExample::MapExample()
{
    //ctor
}

void MapExample::print_data()
{
    for(auto& [key, value] : this->data){
        std::cout << "[" << key << "]" << value << std::endl;
    }
}

MapExample::~MapExample()
{
    //dtor
}
