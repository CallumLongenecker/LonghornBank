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


Account::Account(double initBalance, double initAnnualInterest)
    {
        // Constructor that accepts arguments for the balance and annual interest rate.
        this->balance = initBalance;
        this->annualInterest = initAnnualInterest;
    }

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

