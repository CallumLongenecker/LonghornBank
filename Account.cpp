// File Name: Account_crl3235_asv724_nd8775.cpp
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/29/2022
// Assignment Number 4
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This cpp file contains the method implementations for the Account class

#include "Account.h"
#include <iostream>

//***********************************************************
// Account: the constructor for the Account class
// initBalance: the initial balance of the account
// initAnnualInterest: the initial annual interest rate of the account
// returns: nothing
//***********************************************************
Account::Account(double initBalance, double initAnnualInterest)
    {
        this->balance = initBalance;
        this->annualInterest = initAnnualInterest;
        this->numWithdrawals = 0;
        this->numDeposits = 0;
        this->amountDeposited = 0;
        this->amountWithdrawn = 0;
        this->monthlyInterestEarned = 0;
        this->amountServiceCharges = 0;
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
    this->amountDeposited += amt;
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
    this->amountWithdrawn += amt;
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

    // calculate the monthly interest earned
    double monthlyInterestRate = annualInterest / 100 / 12; 
    // calculate the monthly interest earned
    this->monthlyInterestEarned = this->balance * monthlyInterestRate; 
    this->balance += this->monthlyInterestEarned;
}

//***********************************************************
// monthlyProc: method that processes the monthly procedures
// by calling the calcInt and monthlyProc methods
// returns: nothing
//***********************************************************
void Account::monthlyProc()
{
    this->calcInt();
    this->balance -= amountServiceCharges;
    

}

