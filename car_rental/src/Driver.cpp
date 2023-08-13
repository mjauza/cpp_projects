#include "Driver.h"
#include "Location.h"
#include <iostream>
Driver::Driver(std::string name, float price, Location loc)
{
    this -> name = name;
    this -> price_per_km = price;
    this -> location = loc;
    this -> driving = false;
}

float Driver::get_distance_to_loc(Location &other_loc)
{
    float dist = this -> location.get_distance(other_loc);
    return dist;
}

float Driver::get_ride_price(Location &other_loc)
{
    float dist = this -> get_distance_to_loc(other_loc);
    float ride_price = this -> price_per_km * dist;
    return ride_price;
}

float Driver::get_ride_price(Location &loc1, Location &loc2)
{
    float dist = loc1.get_distance(loc2);
    float ride_price = this -> price_per_km * dist;
    return ride_price;
}
float Driver::get_ride_price(Customer &customer)
{
    Location loc1 = customer.get_curr_loc();
    float price_to_cust = this->get_ride_price(this->location, loc1);

    Location loc2 = customer.get_curr_loc();
    Location loc3 = customer.get_want_loc();
    float price_to_dest = this->get_ride_price(loc2, loc3);
    return price_to_cust + price_to_dest;
}

void Driver::drive_to_loc(const Location &other_loc)
{
    this -> location = other_loc;
    this -> driving = true;
}

bool Driver::is_driving()
{
    return this->driving;
}

bool Driver::operator== ( const Driver &rhs )
{
    return this -> name == rhs.name;
}

void Driver::drive_customer(Customer &customer)
{
    std::cout << this->name << " is at location " << this->location.to_string() << std::endl;
    Location pickup = customer.get_curr_loc();
    std::cout << this->name << " is driving to pick up " << customer.get_name() << " at " << pickup.to_string() <<  std::endl;
    this->drive_to_loc(pickup);
    Location dest = customer.get_want_loc();
    std::cout << this->name << " is driving " << customer.get_name() << " to location " << dest.to_string() << std::endl;
    this->drive_to_loc(dest);
    std::cout << this->name << " and " << customer.get_name() << " arrived at final destination" << std::endl;
    customer.go_to_wanted_location();
}

std::string Driver::get_name()
{
    return this -> name;
}

Driver::~Driver()
{
    //dtor
}
