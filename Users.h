#ifndef USERS_H
#define USERS_H

#include <map>
#include <string>
#include "bankAccount.h"

class Users {
    std::map<std::pair<std::string, std::string>, bankAccount> User;
public:
    Users();
    Users(const std::string& fname, const std::string& lname, const std::string& password, long balance);
    bankAccount getAccountByName(const std::string& fname, const std::string& lname) const;
    void setUserPassword(const std::string& fname, const std::string& lname, const std::string& pass);
    bool userExist(const std::string& fname, const std::string& lname) const;
    void setUser(const std::string& fname, const std::string& lname, const std::string& password, long balance);
};

#endif // USERS_H
