#include <iostream>
#include "Inventory.h"
#include "Product.h"
#include "Sale.h"
#include "SalesMngSys.h"
using namespace std;

int main()
{
    Product soap = Product("soap", 1);
    Product bread = Product("bread", 0.1);
    Product milk = Product("milk", 1.2);

    SalesMngSys sales_sys = SalesMngSys();
    sales_sys.sell_product(soap, 100, 1.1);
    sales_sys.sell_product(bread, 1000, 0.5);
    sales_sys.sell_product(milk, 50, 5);
    //sales_sys.print_sales();
    sales_sys.print_most_profitable();

    Sale sale_soap = Sale(soap, 10, 1.5);
    sale_soap.print_profit();
    Sale sale_bread = Sale(bread, 100, 0.25);
    sale_bread.print_profit();


    Inventory inv = Inventory();
    inv.add_product(soap);
    inv.add_product(milk);
    inv.add_product(bread);

    inv.print_inventory();


    return 0;
}
