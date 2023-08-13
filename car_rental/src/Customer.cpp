#include "Customer.h"

Customer::Customer(std::string name, float budget, Location curr_loc, Location want_loc)
{
    this -> name = name;
    this -> budget = budget;
    this -> curr_loc = curr_loc;
    this -> want_loc = want_loc;
}

void Customer::take_a_ride(Location &other_loc)
{
    this -> curr_loc = other_loc;
}

void Customer::go_to_wanted_location()
{
    this -> take_a_ride(this -> want_loc);
    //this -> want_loc = NULL;
}

Location Customer::get_want_loc()
{
    return this -> want_loc;
}

Location Customer::get_curr_loc()
{
    return this-> curr_loc;
}
std::string Customer::get_name()
{
    return this->name;
}

Customer::~Customer()
{
    //dtor
}
