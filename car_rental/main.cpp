#include <iostream>
#include "Driver.h"
#include "Customer.h"
#include "CarRentSys.h"
#include "Location.h"
using namespace std;

int main()
{

    Driver d_david = Driver("David", 1, Location(1,1));

    Driver d_mia = Driver("Mia", 1, Location(0,0));

    Driver d_peter = Driver("Peter", 0.0001, Location(10,10));

    Customer c_masa = Customer("Masa", 2, Location(0.1,0.1), Location(2,2));


    Customer c_maja = Customer("Masa", 2, Location(0.1,0.1), Location(3,3));

    CarRentSys uber = CarRentSys();
    uber.add_driver(d_david);
    uber.add_driver(d_mia);
    uber.add_driver(d_peter);
    uber.drive_customer(c_masa, "near");
    uber.drive_customer(c_maja, "cheap");
    return 0;
}
