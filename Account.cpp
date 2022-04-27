#include "Account.h"

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
    /*
         A virtual function that updates the balance by: calculating the monthly interest
         earned by the account, and adding this interest to the balance.
     */
    double monthlyInterestRate = annualInterest / 12;
    double monthlyInterest = this->balance * monthlyInterestRate;
    this->balance += monthlyInterest;
}
void Account::monthlyProc()
{
    /*
        A virtual function that subtracts the monthly service charges from the
        balance, calls the calcInt function, and then sets the variables that hold the number of
        withdrawals, number of deposits, and monthly service charges to zero.

    */
    this->balance -= monthlyServiceCharges;
    this->calcInt();
    this->numWithdrawals = 0;
    this->numDeposits = 0;
    this->monthlyServiceCharges = 0;
}

void Savings::deposit(double amt)
{
}
void Savings::withdraw(double amt)
{
}
void Savings::monthlyProc()
{
}

Checking::withdraw(double amt)
{
    /*
        A virtual function that accepts an argument for the amount of the withdrawal.
        The function shall subtract the argument from the balance. It shall also increment the
        variable holding the number of withdrawals.
    */
    if (this->balance - amt < 0)
    {
        return Account::status::FAILURE;
    }
    else
    {
        this->balance -= amt;
        this->numWithdrawals++;
        return Account::status::SUCCESS;
    }
}

Checking::deposit(double amt)
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
        return Account::status::FAILURE;
    }
    else
    {
        this->balance -= amt;
        this->numWithdrawals++;
        return Account::status::SUCCESS;
    }
}
