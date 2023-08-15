#ifndef SALESMNGSYS_H
#define SALESMNGSYS_H
#include "Sale.h"
#include <list>
#include "Inventory.h"
#include "Product.h"
class SalesMngSys
{
    public:
        SalesMngSys();
        void sell_product(Product prod, int qunatity, float sell_price);
        void print_most_profitable();
        void print_sales();
        virtual ~SalesMngSys();

    protected:
        std::list<Sale> sales;



    private:
};

#endif // SALESMNGSYS_H
