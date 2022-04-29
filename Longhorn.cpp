// File Name: Longhorn.cpp
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/29/2022
// Assignment Number 4
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This cpp file executes the program and allows the user to interact
// with the program.

#include <iostream>
#include <string>
#include "Savings.h"
#include "Checking.h"
using namespace std;

int num_transactions = 0;

string *doDepositsAndWithdrawals(Account *account, int numDepositsAndWithdrawals)
{
    string *result = new string[numDepositsAndWithdrawals];
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
            // make the deposit
            result[i] = "Deposit of " + to_string(amount) + " made.";
            account->deposit(amount);
        }
        else if (depositOrWithdrawal == 'W')
        {
            // make a withdrawal
            // if the withdrawal is successful then the result will be "Withdrawal: " + amount
            if (account->withdraw(amount))
            {
                result[i] = "Withdrawal of $" + to_string(amount) + " made.";
            }
            else
            {
                result[i] = "Withdrawal of $" + to_string(amount) + " failed. Service Charge of $15 charged to the account.";
            }
        }
        else
        {
            cout << "Invalid operation. Please try again." << endl;
            i--;
        }
        cout << endl;
    }
    return result;
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
        account = new Checking(initBal, initInterestRate);
    }
    else if (accountType == 'S')
    {
        account = new Savings(initBal, initInterestRate);
    }
    else
    {
        cout << "Invalid input. Please try again." << endl;
    }
    return account;
}

void printIntro()
{
    // print ascii art, credit to https://textart.io/art/tag/bank/1

    cout << "         _._._                       _._._\n";
    cout << "        _|   |_                     _|   |_\n";
    cout << "        | ... |_._._._._._._._._._| ... |\n";
    cout << "        | ||| |  o LONGHORN BANK o  | ||| |\n";
    cout << "        | \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |\n";
    cout << "   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n";
    cout << "  (())) |     |---------------------|     | (()))\n";
    cout << " (())())| \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |(())())\n";
    cout << " (()))()|[-|-]|  :::   .\"-.   :::  |[-|-]|(()))())\n";
    cout << " ()))(()|     | |~|~|  |_|_|  |~|~| |     |()))(()\n";
    cout << "    ||  |_____|_|_|_|__|_|_|__|_|_|_|_____|  ||\n";
    cout << " ~ ~^^ @@@@@@@@@@@@@@/=======\\@@@@@@@@@@@@@@ ^^~ ~\n";
    cout << "      ^~^~                                ~^~^\n";
    cout << endl;

    cout << "Welcome to the Bank of Longhorn!" << endl;
    cout << "Please input your account information: " << endl;
}

void printCow()
{
    // print ascii art cow, credit to https://www.angelfire.com/oh/cow123/ascii.html

    cout << "                   ____                                         ____\n";
    cout << "                      /                                         \n";
    cout << "                      (__________________________________________)\n";
    cout << "                                          (oo)\n";
    cout << "                                   /-------\\/          \n";
    cout << "                                  / |     ||          \n";
    cout << "                                 *  ||----||            \n";
    cout << "                                    ~~    ~~                 \n";
    cout << endl;
}

void printLogo()
{
    // print ascii longhorn logo, credit to https://ascii.co.uk/art/longhorn

    cout << "        888                        888" << endl;
    cout << "        888                        888" << endl;
    cout << "        888                        888" << endl;
    cout << "        888 .d88b. 88888b.  .d88b. 88888b.  .d88b. 888d88888888b." << endl;
    cout << "        888d88\"\"88b888 \"88bd88P\"88b888 \"88bd88\"\"88b888P\"  888 \"88b" << endl;
    cout << "        888888  888888  888888  888888  888888  888888    888  888" << endl;
    cout << "        888Y88..88P888  888Y88b 888888  888Y88..88P888    888  888" << endl;
    cout << "        888 \"Y88P\" 888  888 \"Y88888888  888 \"Y88P\" 888    888  888 " << endl;
    cout << "                                   888" << endl;
    cout << "                              Y8b d88P" << endl;
    cout << "                              \"Y88P\"" << endl;
    cout << endl;
}

void printOutput(string *transaction_log, int num_transactions, double beginning_balance, double amount_deposits, double amount_withdrawals, double interest, double service_charges, double ending_balance)
{
    // Prints the contents of the transaction log
    cout << "Transaction Log: " << endl;
    for (int i = 0; i < num_transactions; i++)
    {
        cout << transaction_log[i] << endl;
    }

    // print the remaining end of month statistics
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Monthly Starting Balance: " << beginning_balance << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Amount Deposited:         " << amount_deposits << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Amount Withdrawn:         " << amount_withdrawals << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Interest Earned:          " << interest << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Service Charges:          " << service_charges << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Monthly Ending Balance:   " << ending_balance << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
}

int main(int argc, char const *argv[])
{
    printIntro();
    Account *account = getInput();
    cout << "Please input the number of deposits and withdrawals: " << endl;
    int numDepositsAndWithdrawals;
    cin >> numDepositsAndWithdrawals;
    // do transactions
    string *transaction_log = doDepositsAndWithdrawals(account, numDepositsAndWithdrawals);
    // print the end of month statistics
    double beginning_balance = account->balance;
    double amount_deposits = account->numDeposits;
    double amount_withdrawals = account->numWithdrawals;
    double interest = account->annualInterest;
    double service_charges = account->numMonthlyServiceCharges;
    double ending_balance = account->balance;
    printOutput(transaction_log, numDepositsAndWithdrawals, beginning_balance, amount_deposits, amount_withdrawals, interest, service_charges, ending_balance);
    return 0;
}
