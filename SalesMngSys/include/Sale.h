#ifndef SALE_H
#define SALE_H
#include "Product.h"

class Sale
{
    public:
        Sale(Product &product, float quantity, float price);
        Product get_product();
        float get_quantity();
        float get_price();
        virtual ~Sale();

    protected:
        Product product;
        float quantity;
        float price;

    private:
};

#endif // SALE_H
