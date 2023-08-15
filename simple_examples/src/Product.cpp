#include "Product.h"
Product::Product()
{

}
Product::Product(std::string name, float price)
{
    this->name = name;
    this->price = price;
}

std::string Product::get_name()
{
    return this->name;
}

float Product::get_price()
{
    return this->price;
}

Product::~Product()
{
    //dtor
}
