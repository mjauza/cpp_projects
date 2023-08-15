#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product
{
    public:
        Product(std::string name, float cost);
        Product(Product &p);
        void operator=(const Product &p);
        virtual ~Product();

        std::string get_name();
        float get_cost();

    protected:
        std::string name;
        float cost;

    private:
};

#endif // PRODUCT_H
