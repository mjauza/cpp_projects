#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "Location.h"

class Customer
{
    public:
        Customer(std::string name, float budget, Location curr_loc, Location want_loc);
        void take_a_ride(Location &other_loc);
        void go_to_wanted_location();
        void set_wanted_location(Location loc);
        Location get_want_loc();
        Location get_curr_loc();
        std::string get_name();
        virtual ~Customer();

    protected:
        std::string name;
        float budget;
        Location curr_loc;
        Location want_loc;

    private:
};

#endif // CUSTOMER_H
