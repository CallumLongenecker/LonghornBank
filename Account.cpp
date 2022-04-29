// File Name: Account.cpp
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/29/2022
// Assignment Number 4
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This cpp file contains the method implementations for the Account class,
// the Savings class, and the Checking class

#include "Account.h"
#include <iostream>

//***********************************************************
// deposit: method that deposits amt money into the account
// by adding amt to the balance
// amt: amount to deposit
// returns: nothing
//***********************************************************
void Account::deposit(double amt)
{
    this->balance += amt;
    this->numDeposits++;
}

//***********************************************************
// withdraw: method that withdraws amt money from the account
// by subtracting amt from the balance
// amt: amount to withdraw
// returns: boolean representing if the withdraw was successful
//***********************************************************
bool Account::withdraw(double amt)
{
    this->balance -= amt;
    this->numWithdrawals++;
    return true;
}

//***********************************************************
// calcInt: method that calculates the interest for the account
// by multiplying the balance by the annual interest rate
// returns: nothing
//***********************************************************
void Account::calcInt()
{

    double monthlyInterestRate = annualInterest / 12;
    double monthlyInterest = this->balance * monthlyInterestRate;
    this->balance += monthlyInterest;
}

//***********************************************************
// monthlyProc: method that processes the monthly procedures
// by calling the calcInt and monthlyProc methods
// returns: nothing
//***********************************************************
void Account::monthlyProc()
{
    this->balance -= numMonthlyServiceCharges;
    this->calcInt();
    this->numWithdrawals = 0;
    this->numDeposits = 0;
    this->numMonthlyServiceCharges = 0;
}

// Savings Account Implementation:

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

// Checking Account Implementation:

Checking::Checking(double initBalance, double initAnnualInterest) : Account(initBalance, initAnnualInterest) {}

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
        std::cout << "Account is overdrawn. Service charge of $15 will be taken from account." << std::endl;

        if (this->balance - 15 < 0)
        {
            // tell user they owe money to bank
            std::cout << "You owe $" << this->balance - 15 << " to the bank." << std::endl;
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
