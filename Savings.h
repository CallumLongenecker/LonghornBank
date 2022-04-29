#ifndef __SAVINGS__
#define __SAVINGS__
#include <iostream>
#include "Account.h"
using namespace std;

class Savings : public Account {
public:
    double monthlyInterest; // stores the monthly interest rate for this account
    bool status;            // stores the status of this account, true if active, false if inactive

    // savings constructor
    Savings(double, double);
    void deposit(double);
    bool withdraw(double);
    void monthlyProc();

    ~Savings() {}
};
#endif