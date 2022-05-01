// File Name: Checking_crl3235_asv724_nd8775.cpp
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/29/2022
// Assignment Number 4
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This cpp file contains the method implementations for the Checking class

#include "Checking.h"
#include <iostream>
using namespace std;

// Checking Account Implementation:

//**********************************************************************
// Checking: the constructor for the Checking class
// initBalance: the initial balance of the account
// initAnnualInterest: the initial annual interest rate of the account
// returns: nothing
//**********************************************************************
Checking::Checking(double initBalance, double initAnnualInterest) 
    : Account(initBalance, initAnnualInterest)
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
        this->amountServiceCharges += 15;
        cout << "Account is overdrawn. Service charge of" 
            <<" $15 will be taken from account." << endl;

        if (this->balance - 15 < 0)
        {
            // tell user they owe money to bank
            cout << "You owe $" << 15 - this->balance 
                << " to the bank." << endl;
        }
        this->balance -= 15;
        cout << endl;
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
    this->amountServiceCharges += 5 + 0.1 * this->numWithdrawals;
    this->Account::monthlyProc();
}

//***********************************************************
// deposit: method that deposits amt money into the account
// by adding amt to the balance
// amt: amount to deposit
// returns: nothing
//***********************************************************
void Checking::deposit(double amt)
{
    this->Account::deposit(amt);
}
