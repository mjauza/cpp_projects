#include "BankAccount.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <cmath>
BankAccount::BankAccount(std::string name, std::string type, float init_amount)
{
    this -> name = name;
    this -> balance = init_amount;
    if(init_amount < 0){
        throw std::invalid_argument("initial amount must be non-negative");
    }
    this -> type = type;
    //ctor
}

float BankAccount::get_balance()
{
    return this -> balance;
}

std::string BankAccount::get_name()
{
    return this -> name;
}

std::string BankAccount::get_type()
{
    return this -> type;
}

std::string BankAccount::toString()
{
    return "Name: " + this->name + ", Type: " + this -> type + ", Balance: " + std::to_string(this -> balance);
}

void BankAccount::deposit(float amount)
{
    if(amount <= 0){
        throw std::invalid_argument("amount must be positive");
    }
    this -> balance += amount;
}

void BankAccount::withdraw(float amount)
{
    if(amount <= 0){
        throw std::invalid_argument("amount must be positive");
    }
    if (amount > this -> balance){
        throw std::invalid_argument("amount must be less than balance");
    }
    this -> balance -= amount;
}

float BankAccount::get_accumalted_balance(float balance, float T, float r, std::string compund_type)
{
    if (balance < 0){
        throw std::invalid_argument("balance must be non-negative");
    }
    if (T < 0){
        throw std::invalid_argument("T must be non-negative");
    }
    float end_balance;
    if(compund_type.compare("simple") == 0){
        end_balance = balance*(1 + r*T);
    } else if(compund_type.compare("cont") == 0){
        end_balance = balance*std::exp(r*T);
    } else {
        throw std::invalid_argument("compound type not supported");
    }
    return end_balance;
}

BankAccount::~BankAccount()
{
    //dtor
}
