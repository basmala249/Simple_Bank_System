#include "bankAccount.h"
#include <iostream>

bankAccount::bankAccount() : balance(0) {}

bankAccount::bankAccount(long b) : balance(b) {}

std::string bankAccount::getPassword() const {
    return password;
}

void bankAccount::setPassword(const std::string& r) {
    password = r;
}

void bankAccount::getBalance() const {
    std::cout << balance << '\n';
}

void bankAccount::addMoney(long m) {
    balance += m;
}

void bankAccount::withdraw(long m) {
    if (m > balance) {
        std::cout << "Money is not available\n";
    } else {
        balance -= m;
    }
}
