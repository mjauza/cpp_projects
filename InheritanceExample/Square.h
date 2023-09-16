#pragma once
#include "Rectangle.h"
#include <string>
class Square : public Rectangle
{
public:
	Square(float a);
	std::string to_string();
};

