#include "Location.h"
#include <cmath>
#include <string>
Location::Location(float x, float y)
{
    this -> x = x;
    this -> y = y;
}
Location::Location()
{
    this -> x = 0;
    this -> y = 0;
}
float Location::get_distance(const Location &loc)
{
    float dist = std::sqrt( std::pow(loc.x  - this->x, 2) + std::pow(loc.y  - this->y, 2));
    return dist;
}

void Location::operator=(const Location& loc)
{
    this -> x = loc.x;
    this -> y = loc.y;
}

std::string Location::to_string()
{
    return "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";

}

Location::~Location()
{
    //dtor
}
