#ifndef INVENTORY_H
#define INVENTORY_H
#include <map>
#include "Product.h"

class Inventory
{
    public:
        Inventory();
        void add_product(Product prod, float quantity);
        void remove_product(Product prod, float quantity);
        virtual ~Inventory();

    protected:
        std::map<std::string, Product> prodcut_map;
        std::map<std::string, float> quantity_map;

    private:
};

#endif // INVENTORY_H
