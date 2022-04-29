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

#include <iostream>

using namespace std;

class Account
{
public:
    double balance;               // double to store the balance for this account
    int numDeposits;              // stores the number of deposits this month for this account
    int numWithdrawals;           // stores the number of withdrawals this month for this account
    double annualInterest;        // stores the annual interest rate for this account
    int numMonthlyServiceCharges; // stores the monthly service charges for this account
    Account() {}                  // default constructor
    Account(double initBalance, double initAnnualInterest)
    {
        // Constructor that accepts arguments for the balance and annual interest rate.
        this->balance = initBalance;
        this->annualInterest = initAnnualInterest;
    }
    virtual void deposit(double amt);
    virtual bool withdraw(double amt);
    virtual void calcInt();
    virtual void monthlyProc();
    ~Account() {}
};

class Savings : public Account
{
public:
    double monthlyInterest; // stores the monthly interest rate for this account
    bool status;            // stores the status of this account, true if active, false if inactive

    // savings constructor
    Savings(double initBalance, double initAnnualInterest) : Account(initBalance, initAnnualInterest)
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
    void deposit(double amt);
    bool withdraw(double amt);
    void monthlyProc();

    ~Savings() {}
};

class Checking : public Account
{
public:
    double serviceCharges; // stores the monthly service charges for this account
    // TODO: make sure checking doesnt allow for annual interest to be set
    // checking constructor
    Checking(double initBalance, double initAnnualInterest);

    void deposit(double amt);
    bool withdraw(double amt);
    void monthlyProc();

    ~Checking() {}
};
