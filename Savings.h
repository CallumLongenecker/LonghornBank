// File Name: Savings_crl3235_asv724_nd8775.h
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/29/2022
// Assignment Number 4
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This header file contains the Savings class
// which is derived from the Account class.

#ifndef __SAVINGS__
#define __SAVINGS__
#include <iostream>
#include "Account.h"
using namespace std;

class Savings : public Account {
public:
    // stores the monthly interest rate for this account
    double monthlyInterest; 
    // stores the status of this account, true if active, false if inactive
    bool status;            

    //***********************************************************
    // Savings: the constructor for the Savings class
    // initBalance: the initial balance of the account
    // initAnnualInterest: the initial annual interest rate of the account
    // returns: nothing
    //***********************************************************
    Savings(double, double);

    //***********************************************************
    // deposit: method that deposits amt money into the account
    // by adding amt to the balance
    // amt: amount to deposit
    // returns: nothing
    //***********************************************************
    void deposit(double);

    //***********************************************************
    // withdraw: method that withdraws amt money from the account
    // by subtracting amt from the balance
    // amt: amount to withdraw
    // returns: boolean representing if the withdraw was successful
    //***********************************************************
    bool withdraw(double);

    //***********************************************************
    // monthlyProc: method that processes the monthly transactions
    // by adding the monthly interest to the balance
    // returns: nothing
    //***********************************************************
    void monthlyProc();

    //***********************************************************
    // ~Savings: destructor method that deletes the account
    // returns: nothing
    //***********************************************************
    ~Savings() {}
};
#endif