#include "Inventory.h"
#include <string>
#include <stdexcept>


Inventory::Inventory()
{
    //ctor
}

void Inventory::add_product(Product prod, float quantity)
{
    if(quantity <= 0){
        throw std::invalid_argument("quantity must be positive");
    }
    std::string prod_name = prod.get_name();
    if (this->prodcut_map.find(prod_name) == this->prodcut_map.end()){
        this->prodcut_map[prod_name] = prod;
        this->quantity_map[prod_name] = quantity;
    }else{
        this->quantity_map[prod_name] += quantity;
    }
}

void Inventory::remove_product(Product prod, float quantity)
{
    if(quantity <= 0){
        throw std::invalid_argument("quantity must be positive");
    }
    std::string prod_name = prod.get_name();
    if(this->prodcut_map.find(prod_name) == this->prodcut_map.end()){
        throw std::invalid_argument("can not remove " + prod_name + " since it is not in inventory");
    }else{
        if(this->quantity_map[prod_name] <  quantity){
            throw std::invalid_argument("Can not remove so much of product "+ prod_name+ " since not enough quantity in inventory");
        }else{
            this->quantity_map[prod_name] -= quantity;
        }
    }

}
Inventory::~Inventory()
{
    //dtor
}
