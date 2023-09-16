#pragma once
#include <string>

class Rectangle
{
public: 
	Rectangle(float a, float b);
	std::string to_string();
	float get_area();
protected:
	float a;
	float b;

};

