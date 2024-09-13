#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class bankAccount {
    std::string password;
    long balance;
public:
    bankAccount();
    bankAccount(long b);
    std::string getPassword() const;
    void setPassword(const std::string& r);
    void getBalance() const;
    void addMoney(long m);
    void withdraw(long m);
};

#endif // BANKACCOUNT_H
