#include "Account.h"
#include <iostream>

Account::Account(double initBalance, double initAnnualInterest)
{
    // Constructor that accepts arguments for the balance and annual interest rate.
    this->balance = initBalance;
    this->annualInterest = initAnnualInterest;
}
void Account::deposit(double amt)
{
    /*
        A virtual function that accepts an argument for the amount of the deposit. The
        function shall add the argument to the account balance. It shall also increment the
        variable holding the number of deposits.
    */
    this->balance += amt;
    this->numDeposits++;
}
void Account::withdraw(double amt)
{
    /*
        A virtual function that accepts an argument for the amount of the withdrawal.
        The function shall subtract the argument from the balance. It shall also increment the
        variable holding the number of withdrawals.
    */
    this->balance -= amt;
    this->numWithdrawals++;
}
void Account::calcInt()
{

    double monthlyInterestRate = annualInterest / 12;
    double monthlyInterest = this->balance * monthlyInterestRate;
    this->balance += monthlyInterest;
}
void Account::monthlyProc()
{
    this->balance -= monthlyServiceCharges;
    this->calcInt();
    this->numWithdrawals = 0;
    this->numDeposits = 0;
    this->monthlyServiceCharges = 0;
}

// Savings Account Implementation:

// savings constructor
SavingsAccount::SavingsAccount(double initBalance, double initAnnualInterest)
    : Account(initBalance, initAnnualInterest)
{
    // SavingsAccount constructor that accepts arguments for the balance and annual interest rate.
    this->numWithdrawals = 0;
    this->numDeposits = 0;
    this->monthlyServiceCharges = 0;

    // check if account is active by checking if balance is above 25
    if (this->balance > 25)
    {
        this->active = true;
    }
    else
    {
        this->active = false;
        // account is not active, print message
        std::cout << "Account is not active. Balance must be greater than $25 to use account." << std::endl;
    }
}

void Savings::deposit(double amt)
{
    this->balance += amt;
    this->numDeposits++;

    // check if deposit makes account active
    if (this->balance > 25)
    {
        this->active = true;
    }
}

void Savings::withdraw(double amt)
{
    if (this->status == true)
    {
        // call the base class withdraw function
        Account::withdraw(amt);
    }
    else
    {
        cout << "Account is inactive. No withdrawal allowed." << endl;
    }
}
void Savings::monthlyProc()
{
    if (this->numWithdrawals > 4)
    {
        this->monthlyServiceCharges += (this->numWithdrawals - 4) * 1;
    }

    if (this->balance < 25)
    {
        this->status = false;
    }

    this->Account::monthlyProc();
}

// Checking Account Implementation:

void Checking::withdraw(double amt)
{
    /*
    Before the base class function is called, this function will determine if a
withdrawal (a check written) will cause the balance to go below $0. If the balance goes
below $0, a service charge of $15 will be taken from the account. (The withdrawal will
not be made.) If there isn’t enough in the account to pay the service charge, the balance
will become negative and the customer will owe the negative amount to the bank.

    */
    if (this->balance - amt < 0)
    {
        this->monthlyServiceCharges += 15;
        std::cout << "Account is overdrawn. Service charge of $15 will be taken from account." << std::endl;
        if(this->balance - 15 < 0){
            // tell user they owe money to bank
            std::cout << "You owe $" << this->balance - 15 << " to the bank." << std::endl;
            
        }
        this->balance -= 15;
    }
    else
    {
        this->Account::withdraw(amt);
    }
}

void Checking::monthlyProc()
{
    this->monthlyServiceCharges += 5 + 0.1 * this->numWithdrawals;
    this->Account::monthlyProc();
}
