// File Name: Account.h
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/29/2022
// Assignment Number 4
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This .h file contains the Account class
// which is the base class for the Savings and Checking classes.
#ifndef __ACCOUNT__
#define __ACCOUNT__
using namespace std;

class Account
{
public:
    double balance;               // double to store the balance for this account
    int numDeposits;              // stores the number of deposits this month for this account
    int numWithdrawals;           // stores the number of withdrawals this month for this account
    double amountDeposited;  // stores the amount deposited this month for this account 
    double amountWithdrawn;      // stores the amount of money withdrawn this month for this account
    double annualInterest;        // stores the annual interest rate for this account
    double monthlyInterestEarned; // stores the monthly interest earned for this account
    int amountServiceCharges; // stores the monthly service charges for this account

    //***********************************************************
    // Account: the constructor for the Account class
    // initBalance: the initial balance of the account
    // initAnnualInterest: the initial annual interest rate of the account
    // returns: nothing
    //***********************************************************
    Account(double, double);

    //***********************************************************
    // deposit: method that deposits amt money into the account
    // by adding amt to the balance
    // amt: amount to deposit
    // returns: nothing
    //***********************************************************
    virtual void deposit(double);

    //***********************************************************
    // withdraw: method that withdraws amt money from the account
    // by subtracting amt from the balance
    // amt: amount to withdraw
    // returns: boolean representing if the withdraw was successful
    //***********************************************************
    virtual bool withdraw(double);

    //***********************************************************
    // calcInt: method that calculates the interest for the account
    // by multiplying the balance by the annual interest rate
    // returns: nothing
    //***********************************************************
    void calcInt();

    //***********************************************************
    // monthlyProc: method that processes the monthly transactions
    // by adding the monthly service charges to the balance
    // returns: nothing
    //***********************************************************
    virtual void monthlyProc();

    //***********************************************************
    // ~Account: destructor method that deletes the account
    // returns: nothing
    //***********************************************************
    virtual ~Account() {}
};
#endif
