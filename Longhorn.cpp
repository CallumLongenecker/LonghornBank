#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

int num_transactions = 0;

string *doDepositsAndWithdrawals(Account *account)
{
    cout << "Please input the number of deposits and withdrawals: " << endl;
    int numDepositsAndWithdrawals;
    cin >> numDepositsAndWithdrawals;

    // get the deposits and withdrawals
    for (int i = 0; i < numDepositsAndWithdrawals; i++)
    {
        // ask the use if they want to make a deposit or withdrawal
        cout << "Would you like to make a deposit or withdrawal? (D = Deposit, W = Withdrawal): " << endl;
        char depositOrWithdrawal;
        cin >> depositOrWithdrawal;
        // ask the user for the amount of the deposit or withdrawal
        cout << "Please input the amount of the deposit or withdrawal: " << endl;
        double amount;
        cin >> amount;

        // make the deposit or withradrawal
        if (depositOrWithdrawal == 'D')
        {
            // make a deposit
            // add the amount to the account
            account->deposit(amount);
        }
        else if (depositOrWithdrawal == 'W')
        {
            // make a withdrawal
            // subtract the amount from the account
            account->withdraw(amount);
        }
        else
        {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

Account *getInput()
{
    /*
    the input must include (per your chosen format):
    • The type of account (savings or checking).
• The month's beginning balance and the annual interest rate.
• The number of deposits and withdrawals (may this data be omitted?).
• The amounts of the deposits and withdrawals made during the month.
    */

    cout << "Please choose your account type (C = Checking, S = Savings): " << endl;
    char accountType;
    cin >> accountType;
    cout << "Please input your account's beginning balance and the annual interest rate: " << endl;
    double initBal, initInterestRate;
    cin >> initBal >> initInterestRate;

    // create the account based on user decision
    Account *account;
    if (accountType == 'C')
    {
        account = new CheckingAccount(initBal, initInterestRate, numDepositsAndWithdrawals);
    }
    else if (accountType == 'S')
    {
        account = new SavingsAccount(initBal, initInterestRate, numDepositsAndWithdrawals);
    }
    else
    {
        cout << "Invalid input. Please try again." << endl;
    }
}

void printOutput(string *transaction_log, double beginning_balance, double amount_deposits, double amount_withdrawals, double interest, double service_charges, double ending_balance)
{
    // Prints the contents of the transaction log
    cout << "Transaction Log: " << endl;
    for (int i = 0; i < num_transactions; i++)
    {
        cout << transaction_log[i] << endl;
    }

    // print the remaining end of month statistics
    cout << "Beginning Balance: " << beginning_balance << endl;
    cout << "Amount Deposited: " << amount_deposits << endl;
    cout << "Amount Withdrawn: " << amount_withdrawals << endl;
    cout << "Interest Earned: " << interest << endl;
    cout << "Service Charges: " << service_charges << endl;
    cout << "Ending Balance: " << ending_balance << endl;
}
int main(int argc, char const *argv[])
{
    Account *account = getInput();
    return 0;
}
