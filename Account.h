// File Name: Account.h
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/29/2022
// Assignment Number 4
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This .h file contains the class definitions for the Account class,
// Savings class, and Checking classs for the Account.cpp file
#ifndef __ACCOUNT__
#define __ACCOUNT__
using namespace std;

class Account
{
public:
    double balance;               // double to store the balance for this account
    int numDeposits;              // stores the number of deposits this month for this account
    int numWithdrawals;           // stores the number of withdrawals this month for this account
    double annualInterest;        // stores the annual interest rate for this account
    int numMonthlyServiceCharges; // stores the monthly service charges for this account
    Account(double, double);
    virtual void deposit(double);
    virtual bool withdraw(double);
    void calcInt();
    virtual void monthlyProc();
    ~Account() {}
};
#endif

