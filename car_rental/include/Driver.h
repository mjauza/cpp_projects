#ifndef DRIVER_H
#define DRIVER_H
#include "Location.h"
#include <string>
#include "Customer.h"
class Driver
{
    public:
        Driver(std::string name, float price, Location loc);
        virtual ~Driver();
        float get_distance_to_loc(Location &other_loc);
        float get_ride_price(Location &loc1, Location &loc2);
        float get_ride_price(Location &other_loc);
        float get_ride_price(Customer &customer);
        void drive_to_loc(const Location &other_loc);
        void drive_customer(Customer &customer);
        bool operator== ( const Driver &rhs );
        bool is_driving();
        std::string get_name();

    protected:
        Location location;
        float price_per_km;
        std::string name;
        bool driving;

    private:
};

#endif // DRIVER_H
