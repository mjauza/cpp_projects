#include "Product.h"
#include <stdexcept>

Product::Product(std::string name, float cost)
{
    this->name = name;
    if (cost <= 0){
        throw std::invalid_argument("cost must be positive");
    }
    this->cost = cost;
}

Product::Product(Product &p)
{
    this->name = p.name;
    this->cost = p.cost;
}

void Product::operator=(const Product &p)
{
    this->name = p.name;
    this->cost = p.cost;
}

std::string Product::get_name()
{
    return this->name;
}

float Product::get_cost()
{
    return this->cost;
}

Product::~Product()
{
    //dtor
}
