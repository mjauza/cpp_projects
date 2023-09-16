// InheritanceExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rectangle.h"
#include "Square.h"


void rectangle_example();
void square_example();

int main()
{
    square_example();
    //rectangle_example();
    return 0;
}

void square_example()
{
    Square s = Square(3);
    std::cout << s.to_string() << " ; area: " << s.get_area() << std::endl;
}

void rectangle_example()
{
    Rectangle r = Rectangle(2, 3);
    std::cout << r.to_string() << "; area: " << r.get_area() << std::endl;
}