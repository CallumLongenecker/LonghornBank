// File Name: Savings_crl3235_asv724_nd8775.cpp
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/29/2022
// Assignment Number 4
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This cpp file contains the method implementations for the Savings class


#include "Savings.h"
// Savings Account Implementation:

//*************************************************************************
// Savings: the constructor for the Savings class
// initBalance: the initial balance of the account
// initAnnualInterest: the initial annual interest rate of the account
// returns: nothing
//*************************************************************************
Savings::Savings(double initBalance, double initAnnualInterest) 
    : Account(initBalance, initAnnualInterest)
    {
        // SavingsAccount constructor that accepts arguments
        // for the balance and annual interest rate.
        this->numWithdrawals = 0;
        this->numDeposits = 0;
        this->amountServiceCharges = 0;

        // check if account is active by checking if balance is above 25
        if (this->balance > 25)
        {
            this->status = true;
        }
        else
        {
            this->status = false;
            // account is not active, print message
            cout << "Account is not active. Balance must be greater " 
                << "than $25 to use account." << endl;
            cout << endl;
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
   //check current status of account
   bool currStatus = this->status;

    this->balance += amt;
    this->amountDeposited += amt;
    this->numDeposits++;

    // check if deposit makes account active
    if (this->balance > 25)
    {
        this->status = true;
        if(currStatus == false) {
           cout << "Account is now active. Thank you for your deposit!" 
            << endl;
        }
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
   if(this->balance - amt < 25){
      this->status = false;
   }
    if (this->status == true)
    {
        // call the base class withdraw function
        Account::withdraw(amt);
        return true;
    }
    else
    {
        cout << "Account is inactive. No withdrawal allowed." << endl;
        cout << endl;
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
        this->amountServiceCharges += (this->numWithdrawals - 4) * 1;
    }


    this->calcInt();

    bool activePreCharges = this->status;

    this->balance -= amountServiceCharges;
    if (this->balance < 25 && activePreCharges)
    { 
        cout << "Account is inactive as a result of the monthly" 
            << " service charges being taken from the account.\n";
         cout << endl;
        this->status = false;
    }
    
}