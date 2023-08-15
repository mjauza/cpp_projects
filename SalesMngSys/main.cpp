#include <iostream>
#include "Product.h"
#include "SalesSys.h"
using namespace std;

int main()
{
    Product soap("soap", 1);
    Product tooth_paste("tooth paste", 2);
    Product bread("bread", 0.5);
    Product bmw("BMW", 10000);

    SalesSys sale_sys = SalesSys();
    sale_sys.add_to_inv(soap, 100);
    sale_sys.add_to_inv(tooth_paste, 200);
    sale_sys.add_to_inv(bread, 1000);
    sale_sys.add_to_inv(bmw, 1);

    sale_sys.sell_product(soap, 20, 1.1);
    sale_sys.sell_product(tooth_paste, 150, 1.5);
    sale_sys.sell_product(bread, 1000, 1);
    sale_sys.sell_product(bmw, 1, 15000);

    sale_sys.print_most_popuar_prod();
    sale_sys.print_most_profitable_prod();



    return 0;
}
