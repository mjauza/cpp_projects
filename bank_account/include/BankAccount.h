#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

class BankAccount
{
    public:
        BankAccount(std::string name, std::string type, float init_amount = 0);
        virtual ~BankAccount();
        float get_balance();
        std::string get_name();
        std::string get_type();
        std::string toString();
        void deposit(float amount);
        void withdraw(float amount);
        static float get_accumalted_balance(float balance, float T, float r, std::string compund_type);

    protected:
        float balance;
        std::string type;
        std::string name;

    private:
};

#endif // BANKACCOUNT_H
