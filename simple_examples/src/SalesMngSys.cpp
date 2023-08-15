#include "SalesMngSys.h"
#include "Sale.h"
#include <string>
#include <map>
#include <iostream>
SalesMngSys::SalesMngSys()
{
    //ctor
}

void SalesMngSys::sell_product(Product prod, int qunatity, float sell_price)
{
    float f_q = (float)qunatity;
    Sale sale = Sale(prod, f_q,  sell_price);
    this->sales.push_back(sale);
}

void SalesMngSys::print_sales()
{
    std::list<Sale>::iterator it;
    for(it = this->sales.begin(); it != this->sales.end(); ++it){
        std::string name = it->get_product().get_name();
        std::cout << name << std::endl;
    }

}

void SalesMngSys::print_most_profitable()
{

    std::map<std::string, float> profit_map;
    std::list<Sale>::iterator it;
    for(it = (this->sales).begin(); it != (this->sales).end(); ++it){
        float profit = it->get_profit();
        std::string product_name = it->get_product().get_name();
        if(profit_map.find(product_name) == profit_map.end()){
            profit_map[product_name] = profit;
        }else{
            profit_map[product_name] += profit;
        }
    }

    std::map<std::string, float>::iterator mit;
    std::string best_prod = profit_map.begin()->first;
    float best_profit = profit_map.begin()->second;
    for(mit = profit_map.begin(); mit != profit_map.end(); ++mit){
        std::string prod_name = mit->first;
        float profit = mit->second;
        if(profit > best_profit){
            best_prod = prod_name;
            best_profit = profit;
        }
    }


    std::cout << "Most profitable product is " << best_prod << " with profit of " << best_profit << std::endl;

}

SalesMngSys::~SalesMngSys()
{
    //dtor
}
