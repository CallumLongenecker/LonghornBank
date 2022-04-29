#ifndef __CHECKING__
#define __CHECKING__
#include "Account.h"
using namespace std;


class Checking : public Account
{
public:
    double serviceCharges; // stores the monthly service charges for this account
    // TODO: make sure checking doesnt allow for annual interest to be set
    // checking constructor
    Checking(double, double);
        

    void deposit(double);
    bool withdraw(double);
    void monthlyProc();

    ~Checking() {}
};
#endif