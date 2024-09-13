#include "Users.h"

Users::Users() {}

Users::Users(const std::string& fname, const std::string& lname, const std::string& password, long balance) {
    bankAccount c(balance);
    c.setPassword(password);
    User[{fname, lname}] = c;
}

bankAccount Users::getAccountByName(const std::string& fname, const std::string& lname) const {
    return User.at({fname, lname});
}

void Users::setUserPassword(const std::string& fname, const std::string& lname, const std::string& pass) {
    User[{fname, lname}].setPassword(pass);
}

bool Users::userExist(const std::string& fname, const std::string& lname) const {
    return User.find({fname, lname}) != User.end();
}

void Users::setUser(const std::string& fname, const std::string& lname, const std::string& password, long balance) {
    bankAccount c(balance);
    c.setPassword(password);
    User[{fname, lname}] = c;
}
