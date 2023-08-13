#ifndef CARRENTSYS_H
#define CARRENTSYS_H
#include "Customer.h"
#include "Driver.h"
#include <vector>
#include <string>
#include <list>

class CarRentSys
{
    public:
        CarRentSys();
        virtual ~CarRentSys();
        void add_driver(Driver d);
        void remove_driver(Driver driver);
        float calc_route_price(Customer customer, Driver driver);
        std::list<Driver> get_avaliable_drivers();
        Driver find_nearest_driver(Customer customer);
        Driver find_cheapest_driver(Customer customer);
        void drive_customer(Customer &customer, std::string drive_type);



    protected:
        std::list<Driver> drivers;


    private:
};

#endif // CARRENTSYS_H
