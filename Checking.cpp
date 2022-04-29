#include "Checking.h"
#include <iostream>
using namespace std;

// Checking Account Implementation:

Checking::Checking(double initBalance, double initAnnualInterest) : Account(initBalance, initAnnualInterest)
{
}

//***********************************************************
// withdraw: withdraws amt money from the account and
// determines if a withdrawal will cause balance to go below 0
// and updates user account accordingly
// amt: amount to withdraw
// returns: boolean representing if the withdraw was successful
//***********************************************************
bool Checking::withdraw(double amt)
{
    if (this->balance - amt < 0)
    {
        this->numMonthlyServiceCharges += 15;
        cout << "Account is overdrawn. Service charge of $15 will be taken from account." << endl;

        if (this->balance - 15 < 0)
        {
            // tell user they owe money to bank
            cout << "You owe $" << this->balance - 15 << " to the bank." << endl;
        }
        this->balance -= 15;
        return false;
    }

    this->Account::withdraw(amt);
    return true;
}

//***********************************************************
// monthlyProc: method that processes the monthly procedures
// returns: nothing
//***********************************************************
void Checking::monthlyProc()
{
    this->numMonthlyServiceCharges += 5 + 0.1 * this->numWithdrawals;
    this->Account::monthlyProc();
}

void Checking::deposit(double amt)
{
    this->Account::deposit(amt);
}
