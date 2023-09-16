#include "Square.h"


Square::Square(float a) : Rectangle(a,a)
{

}

std::string Square::to_string()
{
	std::string res = "Square( " + std::to_string(this->a) + " )";
	return res;
}