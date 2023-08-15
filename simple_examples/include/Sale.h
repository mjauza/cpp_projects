#ifndef SALE_H
#define SALE_H
#include "Product.h"

class Sale
{
    public:
        Sale(Product product, float quantity, float sell_price);
        Product get_product();
        float get_quantity();
        float get_sell_price();
        float get_profit();
        void print_profit();
        virtual ~Sale();

    protected:
        Product product;
        float quantity;
        float sell_price;


    private:
};

#endif // SALE_H
