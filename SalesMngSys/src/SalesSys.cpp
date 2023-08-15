#include "SalesSys.h"
#include "Sale.h"
#include <string>
#include <iostream>
SalesSys::SalesSys()
{
    //ctor
}

void SalesSys::add_to_inv(Product prod, float quantity)
{
    this->inv.add_product(prod, quantity);
}

void SalesSys::sell_product(Product prod, float quantity, float price)
{
    Sale sale = Sale(prod, quantity, price);
    this->inv.remove_product(prod, quantity);
    this->sales.push_back(sale);
}

std::tuple<std::string, float> SalesSys::get_most_popuar_prod()
{
    std::list<Sale>::iterator it;
    std::map<std::string, float> count_map;
    for (it = this->sales.begin(); it != this->sales.end(); ++it){

        std::string prod_name = it->get_product().get_name();
        float quantity = it->get_quantity();
        if(count_map.find(prod_name) == count_map.end()){
            count_map[prod_name] = quantity;
        }else{
            count_map[prod_name] += quantity;
        }
    }

    std::string best_prod;
    float highest_quant = -10;
    std::map<std::string, float>::iterator mit;
    for (mit = count_map.begin(); mit != count_map.end(); mit++){
        std::string prod_name = mit->first;
        float quant = mit->second;
        if(quant > highest_quant){
            highest_quant = quant;
            best_prod = prod_name;
        }
    }

    std::tuple<std::string, float> res(best_prod, highest_quant);

    return res;
}

void SalesSys::print_most_popuar_prod()
{
    std::tuple<std::string, float> res  = get_most_popuar_prod();
    std::string prod_name = std::get<0>(res);
    float quant= std::get<1>(res);

    //tie(prod_name, quant) =

    std::cout << "Most popular product is " << prod_name << " , which was sold " << std::to_string(quant) << " times" << std::endl;
}

std::tuple<std::string, float> SalesSys::get_most_profitable_prod()
{
    std::list<Sale>::iterator it;
    std::map<std::string, float> profit_map;
    for (it = this->sales.begin(); it != this->sales.end(); ++it){

        std::string prod_name = it->get_product().get_name();
        float quantity = it->get_quantity();
        float sell_price = it->get_price();
        float buy_price = it->get_product().get_cost();
        float profit = quantity*(sell_price - buy_price);
        if(profit_map.find(prod_name) == profit_map.end()){
            profit_map[prod_name] = profit;
        }else{
            profit_map[prod_name] += profit;
        }
    }

    std::string best_prod = profit_map.begin()->first;
    float highest_profit = profit_map.begin()->second;
    std::map<std::string, float>::iterator mit;
    for (mit = profit_map.begin(); mit != profit_map.end(); mit++){
        std::string prod_name = mit->first;
        float profit = mit->second;
        if(profit > highest_profit){
            highest_profit = profit;
            best_prod = prod_name;
        }
    }

    std::tuple<std::string, float> res(best_prod, highest_profit);

    return res;
}

void SalesSys::print_most_profitable_prod()
{
    std::tuple<std::string, float> res  = get_most_profitable_prod();
    std::string prod_name = std::get<0>(res);
    float profit = std::get<1>(res);

    //tie(prod_name, profit) = ;

    std::cout << "Most profitable product is " << prod_name << " which has a profit/loss of " << std::to_string(profit) << std::endl;
}


SalesSys::~SalesSys()
{
    //dtor
}
