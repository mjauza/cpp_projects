#include <iostream>
#include "BankAccount.h"
#include <string>
using namespace std;

int main()
{
    BankAccount ba = BankAccount("David","checking", 1);
    ba.deposit(1.32);
    ba.withdraw(1);
    std::string ba_str = ba.toString();
    cout << ba_str << endl;


    float simple_comp = BankAccount::get_accumalted_balance(1, 10, 0.05, "simple");
    float cont_comp = BankAccount::get_accumalted_balance(1, 10, 0.05, "cont");

    cout << "Simple compound balance " << std::to_string(simple_comp) << endl;
    cout << "Continous compound balance " << std::to_string(cont_comp) << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
