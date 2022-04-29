// File Name: Checking_crl3235_asv724_nd8775.h
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/29/2022
// Assignment Number 4
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This header file contains the Checking class
// which is derived from the Account class.


#ifndef __CHECKING__
#define __CHECKING__
#include "Account.h"
using namespace std;


class Checking : public Account
{
public:
    // ***********************************************************
    // Checking: the constructor for the Checking class
    // initBalance: the initial balance of the account
    // initAnnualInterest: the initial annual interest rate of the account
    // returns: nothing
    // ***********************************************************
    Checking(double, double);
        
    // ***********************************************************
    // deposit: method that deposits amt money into the account
    // by adding amt to the balance
    // amt: amount to deposit
    // returns: nothing
    // ***********************************************************
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
    // by adding the monthly service charges to the balance
    // returns: nothing
    //***********************************************************
    void monthlyProc();

    //***********************************************************
    // ~Checking: destructor method that deletes the account
    // returns: nothing
    //**********************************************************
    ~Checking() {}
};
#endif