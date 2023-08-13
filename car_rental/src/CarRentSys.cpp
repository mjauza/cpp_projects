#include "CarRentSys.h"
#include <list>
#include <string>
#include <stdexcept>
#include <iostream>
CarRentSys::CarRentSys()
{

}

void CarRentSys::add_driver(Driver d)
{
    this -> drivers.push_back(d);
}

void CarRentSys::remove_driver(Driver driver)
{
    this -> drivers.remove(driver);
}

float CarRentSys::calc_route_price(Customer customer, Driver driver)
{
    Location want = customer.get_want_loc();
    float price = driver.get_ride_price(want);
    return price;
}

std::list<Driver> CarRentSys::get_avaliable_drivers()
{
    std::list<Driver> avlb_drivers;
    std::list<Driver>::iterator it;
    for (it = this->drivers.begin(); it != this->drivers.end(); ++it){
        bool drv = it->is_driving();
        if(!drv){
            avlb_drivers.push_back(*it);
        }
    }
    return avlb_drivers;
}
Driver CarRentSys::find_nearest_driver(Customer customer)
{
    std::list<Driver> avlb_drivers = get_avaliable_drivers();
    Driver best_driver = avlb_drivers.front();
    Location curr = customer.get_curr_loc();
    float best_dist = best_driver.get_distance_to_loc(curr);
    //std::cout << "Best Driver init " << best_driver.get_name() << std::endl;
    //std::cout << "Best Driver init dist " << std::to_string(best_dist) << std::endl;
    std::list<Driver>::iterator it;
    for (it = avlb_drivers.begin(); it != avlb_drivers.end(); ++it){
        Location curr = customer.get_curr_loc();
        float dist = it->get_distance_to_loc(curr);
        //std::cout << "it driver " << it->get_name() << std::endl;
        //std::cout << "id driver dist " << std::to_string(dist) << std::endl;
        if( dist < best_dist){
            best_driver = *it;
            best_dist = dist;
        }
    }
    return best_driver;
}

Driver CarRentSys::find_cheapest_driver(Customer customer)
{
    std::list<Driver> avlb_drivers = get_avaliable_drivers();
    Driver best_driver = avlb_drivers.front();
    float best_price = best_driver.get_ride_price(customer);
    std::list<Driver>::iterator it;
    for (it = avlb_drivers.begin(); it != avlb_drivers.end(); ++it){
        float price = it->get_ride_price(customer);
        if(price < best_price){
            best_driver = *it;
            best_price = price;
        }
    }
    return best_driver;
}
void CarRentSys::drive_customer(Customer &customer, std::string drive_type)
{
    //Driver best_driver;
    if(drive_type.compare("cheap") == 0){
        Driver best_driver = this->find_cheapest_driver(customer);
        best_driver.drive_customer(customer);
    }else if (drive_type.compare("near") == 0){
        Driver best_driver = this->find_nearest_driver(customer);
        best_driver.drive_customer(customer);
    }else{
        throw std::invalid_argument("drive type not supported");
    }


}

CarRentSys::~CarRentSys()
{
    //dtor
}
