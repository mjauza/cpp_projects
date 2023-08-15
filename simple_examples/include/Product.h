#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product
{
    public:
        Product(std::string name, float price);
        Product();
        std::string get_name();
        float get_price();
        virtual ~Product();

    protected:
        std::string name;
        float price;


    private:
};

#endif // PRODUCT_H
