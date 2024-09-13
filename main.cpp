#include <iostream>
#include "Users.h"
#include "bankAccount.h"

using namespace std;

int main() {
    Users newCommer;
    string fname, lname, pass;
    long balance;

    cout << "Hello Customer!\nHope you are good\n";
    cout << "Enter Your Information:\n";
    cout << "Your First Name: ";
    cin >> fname;
    cout << "Your Last Name: ";
    cin >> lname;
    cout << "Enter Your Password: ";
    cin >> pass;

    int n;
    cout << "Click based on what you want:\n";
    cout << "1: Create new Account 2: Get my Account 0: To leave\n";
    cin >> n;

    while (true) {
        if (n == 1) {
            if (newCommer.userExist(fname, lname)) {
                cout << "You already have an account.\n";
                cout << "Re-enter your choice: ";
                cin >> n;
                continue;
            }
            cout << "Enter Your Start Balance: ";
            cin >> balance;
            newCommer.setUser(fname, lname, pass, balance);
            cout << "Account created successfully.\n";
            cout << "Re-enter your choice: ";
            cin >> n;
            continue;
        } else if (n == 2) {
            if (!newCommer.userExist(fname, lname)) {
                cout << "No User Found.\n";
                cout << "Re-enter your choice: ";
                cin >> n;
                continue;
            }
            cout << "Enter your pass : ";
            cin >> pass;
            bankAccount c = newCommer.getAccountByName(fname, lname);
            if (c.getPassword() != pass) {
                cout << "Incorrect Password! Please re-enter your password.\n";
                continue;
            }

            int num;
            cout << "Here are your options:\n";
            cout << "1: Add Money  2: Withdraw 3: Change Your Password 4: Get Information on Balance 0: To leave\n";
            cout << "Enter your choice: ";
            while (cin >> num) {
                if (num == 1) {
                    long money;
                    cout << "Enter amount you want to add: ";
                    cin >> money;
                    c.addMoney(money);
                    cout << "Money is added successfully.\n";
                } else if (num == 2) {
                    long amount;
                    cout << "Enter your needed amount: ";
                    cin >> amount;
                    c.withdraw(amount);
                } else if (num == 3) {
                    cout << "Enter your new password: ";
                    string newPass;
                    cin >> newPass;
                    c.setPassword(newPass);
                } else if (num == 4) {
                    c.getBalance();
                } else if (num == 0) {
                    break;
                } else {
                    cout << "Sorry! No available option.\n";
                }
                cout << "Here are your options:\n";
                cout << "1: Add Money  2: Withdraw 3: Change Your Password 4: Get Information on Balance 0: To leave\n";
                cout << "Enter your choice: ";
            }
        } else if (n == 0) {
            break;
        } else {
            cout << "Oops! No available option.\n";
        }
        cout << "Click based on what you want:\n";
        cout << "1: Create new Account 2: Get my Account 0: To leave\n";
        cin >> n;
    }

    return 0;
}
