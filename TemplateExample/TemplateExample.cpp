// TemplateExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Basic.h"
#include <string>
void basic_example();

void calculator_example();

int main()
{
    //basic_example();
    calculator_example();
    std::cout << "Hello World!\n";
}


void basic_example()
{
    Basic<std::string> b_str = Basic<std::string>("David");
    std::cout << "b_str = " << b_str.get_var() << std::endl;

    Basic<float> b_flt = Basic<float>(3.14);
    std::cout << "b_flt = " << b_flt.get_var() << std::endl;

    Basic<int> b_int = Basic<int>(3);
    std::cout << "b_int = " << b_int.get_var() << std::endl;
}


void calculator_example()
{
    Calculator<int> c_int = Calculator<int>(2, 3);
    std::cout << "Calcualtor int: " << std::endl;
    c_int.display_results();

    Calculator<double> c_dbl = Calculator<double>(2.12, 3.423);
    std::cout << "Calcualtor double: " << std::endl;
    c_dbl.display_results();
}