#include "Inventory.h"
#include <iostream>
Inventory::Inventory()
{
    //ctor
}

void Inventory::add_product(Product prod)
{
    this->products.push_back(prod);
}

void Inventory::print_inventory()
{
    std::list<Product>::iterator it;
    for (it = this->products.begin(); it != this->products.end(); ++it){
        std::cout << "Name: " << it->get_name() << ", Price: " << it->get_price() << std::endl;
    }
}

Inventory::~Inventory()
{
    //dtor
}
