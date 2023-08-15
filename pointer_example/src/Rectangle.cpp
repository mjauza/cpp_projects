#include "Rectangle.h"

Rectangle::Rectangle()
{
    //ctor
}
Rectangle::Rectangle(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Rectangle::get_area()
{
    return this->x * this->y;
}

std::string Rectangle::to_string()
{
    std::string res = "Rectangle(" + std::to_string(this->x) + " , " +  std::to_string(this->y) + ")";
    return res;
}
Rectangle::~Rectangle()
{
    //dtor
}
