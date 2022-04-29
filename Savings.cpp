#include "Savings.h"
// Savings Account Implementation:

Savings::Savings(double initBalance, double initAnnualInterest) : Account(initBalance, initAnnualInterest)
    {
        // SavingsAccount constructor that accepts arguments for the balance and annual interest rate.
        this->numWithdrawals = 0;
        this->numDeposits = 0;
        this->numMonthlyServiceCharges = 0;

        // check if account is active by checking if balance is above 25
        if (this->balance > 25)
        {
            this->status = true;
        }
        else
        {
            this->status = false;
            // account is not active, print message
            cout << "Account is not active. Balance must be greater than $25 to use account." << endl;
        }
    }

//***********************************************************
// deposit: method that deposits amt money into the account
// and ensures that the account is active
// amt: amount to deposit
// returns: nothing
//***********************************************************
void Savings::deposit(double amt)
{
    this->balance += amt;
    this->numDeposits++;

    // check if deposit makes account active
    if (this->balance > 25)
    {
        this->status = true;
    }
    
}

//***********************************************************
// withdraw: withdraws amt money from the account if the
// account is active and otherwise prints error message
// amt: amount to withdraw
// returns: boolean representing if the withdraw was successful
//***********************************************************
bool Savings::withdraw(double amt)
{
    if (this->status == true)
    {
        // call the base class withdraw function
        Account::withdraw(amt);
        return true;
    }
    else
    {
        cout << "Account is inactive. No withdrawal allowed." << endl;
        return false;
    }
}

//***********************************************************
// monthlyProc: method that processes the monthly procedures
// and ensures that the account is active
// returns:nothing
//***********************************************************
void Savings::monthlyProc()
{
    if (this->numWithdrawals > 4)
    {
        this->numMonthlyServiceCharges += (this->numWithdrawals - 4) * 1;
    }

    if (this->balance < 25)
    {
        this->status = false;
    }

    this->Account::monthlyProc();
}