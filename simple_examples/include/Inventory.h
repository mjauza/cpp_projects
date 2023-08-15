#ifndef INVENTORY_H
#define INVENTORY_H
#include "Product.h"
#include <list>
class Inventory
{
    public:
        Inventory();
        void add_product(Product prod);
        void print_inventory();
        //void find_cheapeast_product();
        virtual ~Inventory();

    protected:
        std::list<Product> products;

    private:
};

#endif // INVENTORY_H
