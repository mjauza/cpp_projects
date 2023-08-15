#include "Sale.h"
#include <stdexcept>
#include "Product.h"
Sale::Sale(Product &product, float quantity, float price)
{
    this->product = product;
    if(quantity <= 0){
        throw std::invalid_argument("quantity must be positive");
    }
    this->quantity = quantity;
    this->price = price;
}

Product Sale::get_product()
{
    return this->product;
}

float Sale::get_quantity()
{
    return this->quantity;
}

float Sale::get_price()
{
    return this->price;
}

Sale::~Sale()
{
    //dtor
}
