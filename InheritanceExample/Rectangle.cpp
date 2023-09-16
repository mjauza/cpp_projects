#include "Rectangle.h"


Rectangle::Rectangle(float a, float b)
{
	this->a = a;
	this->b = b;
}

float Rectangle::get_area()
{
	return this->a * this->b;
}

std::string Rectangle::to_string()
{
	std::string res = "Rectangle( " + std::to_string(this->a) + " , " + std::to_string(this->b) + " )";
	return res;
}