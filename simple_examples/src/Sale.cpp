#include "Sale.h"
#include <iostream>
#include <string>
Sale::Sale(Product product, float quantity, float sell_price)
{
    this->product=product;
    this->quantity=quantity;
    this->sell_price=sell_price;
}

Product Sale::get_product()
{
    return this->product;
}

float Sale::get_quantity()
{
    return this->quantity;
}

float Sale::get_sell_price()
{
    return this->sell_price;
}

float Sale::get_profit()
{
    float profit = this->quantity*(this->sell_price - this->product.get_price());
    return profit;
}

void Sale::print_profit()
{
    float profit = this->get_profit();
    std::string product_name = this->product.get_name();
    std::cout << "Product " << product_name << " generated profit of " << std::to_string(profit) << std::endl;
}

Sale::~Sale()
{
    //dtor
}
