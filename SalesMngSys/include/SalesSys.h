#ifndef SALESSYS_H
#define SALESSYS_H
#include "Sale.h"
#include <list>
#include "Inventory.h"
#include "Product.h"
#include <tuple>
#include <string>
class SalesSys
{
    public:
        SalesSys();
        void add_to_inv(Product prod, float quantity);
        void sell_product(Product prod, float quantity, float price);
        std::tuple<std::string, float> get_most_popuar_prod();
        void print_most_popuar_prod();
        std::tuple<std::string, float> get_most_profitable_prod();
        void print_most_profitable_prod();
        virtual ~SalesSys();

    protected:
        std::list<Sale> sales;
        Inventory inv;



    private:
};

#endif // SALESSYS_H
