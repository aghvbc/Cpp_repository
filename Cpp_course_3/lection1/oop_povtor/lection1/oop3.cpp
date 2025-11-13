#include <iostream>


class BankAccount {
private:
    int accountNumber;
    double balance;
public:
    BankAccount(int ID, double balance) : accountNumber(ID), balance(balance) {}

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            std::cout << "Error";
        }
        
    }

    void withdraw(double amount) {
        if (amount > 0 && amount < balance) {
            balance -= amount;
        } else {
            std::cout << "Error" << ".Stop transaction!" << std::endl;
        }
    }
};