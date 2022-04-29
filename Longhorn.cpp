// File Name: Longhorn_crl3235_asv724_nd8775.cpp
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
#include <iomanip>
#include <string>
#include "Savings.h"
#include "Checking.h"
using namespace std;

//***********************************************************
// doDepositsAndWithdrawals: method that handles the user
// deposits and withdrawals from the accounts
// account: the account to deposit and withdraw from
// numDepositsAndWithdrawals: the number of deposits and
// withdrawals to perform
// returns: a string pointer storing all the transactions
//***********************************************************
string *doDepositsAndWithdrawals(Account *account, 
    int numDepositsAndWithdrawals)
{
    string *result = new string[numDepositsAndWithdrawals];
    // get the deposits and withdrawals
    for (int i = 0; i < numDepositsAndWithdrawals; i++)
    {
        // ask the use if they want to make a deposit or withdrawal
        cout << "Would you like to make a deposit or withdrawal?" 
            << " (D = Deposit, W = Withdrawal): " << endl;
        char depositOrWithdrawal; // stores the user's choice
        cin >> depositOrWithdrawal;
        // ask the user for the amount of the deposit or withdrawal
        cout << "Please input the amount of the deposit or withdrawal: "
            << endl;
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
            if (account->withdraw(amount))
            {
                result[i] = "Withdrawal of $" + to_string(amount) 
                    + " made.";
            }
            else
            {
                result[i] = "Withdrawal of $" + to_string(amount) 
                    + " failed." 
                    + " Service Charge of $15 charged to the account.";
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

//***********************************************************
// getInput: method that gets the account setup information
// returns: an account pointer to the account that was created
//***********************************************************
Account *getInput()
{
    cout << "Please choose your account type (C = Checking, S = Savings): ";
    char accountType;
    double initBal, initInterestRate;
    cin >> accountType;
    cout << endl;
    cout << "Please input your account's beginning balance: ";
    cin >> initBal;
    cout << "Please input your account's annual interest rate percentage: ";
    cin >> initInterestRate;

    Account *account; // the account to return
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

//***********************************************************
// printIntro: method that prints the program's introduction
// returns: nothing
//***********************************************************
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
    cout << " (())())| \"\"\" |  \"\"\"   " 
        << " \"\"\"    \"\"\"  | \"\"\" |(())())\n";
    cout << " (()))()|[-|-]|  :::   .\"-.   :::  |[-|-]|(()))())\n";
    cout << " ()))(()|     | |~|~|  |_|_|  |~|~| |     |()))(()\n";
    cout << "    ||  |_____|_|_|_|__|_|_|__|_|_|_|_____|  ||\n";
    cout << " ~ ~^^ @@@@@@@@@@@@@@/=======\\@@@@@@@@@@@@@@ ^^~ ~\n";
    cout << "      ^~^~                                ~^~^\n";
    cout << endl;

    cout << "Welcome to the Bank of Longhorn!" << endl;
    cout << endl;
    cout << "Please input your account information: " << endl;
}

//***********************************************************
// printCow: method that prints a cow
// returns: nothing
//***********************************************************
void printCow()
{
    // print ascii art cow, credit to 
    //https://www.angelfire.com/oh/cow123/ascii.html

    cout << "                   " 
        << "____                                         ____\n";
    cout << "                      " 
        << "/                                         \n";
    cout << "                      " 
        << "(__________________________________________)\n";
    cout << "                                          (oo)\n";
    cout << "                                   /-------\\/          \n";
    cout << "                                  / |     ||          \n";
    cout << "                                 *  ||----||            \n";
    cout << "                                   " 
        << " ~~    ~~                 \n";
    cout << endl;
}

//***********************************************************
// printLogo: method that prints the bank's logo
// returns: nothing
//***********************************************************
void printLogo()
{
    // print ascii longhorn logo, credit to 
    // https://ascii.co.uk/art/longhorn

    cout << "        888                        888" << endl;
    cout << "        888                        888" << endl;
    cout << "        888                        888" << endl;
    cout << "        888 .d88b. 88888b.  .d88b. 88888b. " 
        << " .d88b. 888d88888888b." << endl;
    cout << "        888d88\"\"88b888 \"88bd88P\"88b888 " 
        << "\"88bd88\"\"88b888P\"  888 \"88b" << endl;
    cout << "        888888  888888  888888  888888 "
        << " 888888  888888    888  888" << endl;
    cout << "        888Y88..88P888  888Y88b 888888 " 
        << " 888Y88..88P888    888  888" << endl;
    cout << "        888 \"Y88P\" 888  888 \"Y88888888 " 
        << " 888 \"Y88P\" 888    888  888 " << endl;
    cout << "                                   888" << endl;
    cout << "                              Y8b d88P" << endl;
    cout << "                              \"Y88P\"" << endl;
    cout << endl;
}

//***********************************************************
// getLongest: method that finds the longest integer
// length in an array
// nums: an array of integers
// numsSize: the size of the array
// returns: the length of the longest integer in the array
//***********************************************************
int getLongest(int *nums, int numsSize)
{
    int longest = 0; // initialize the longest integer to 0
    for (int i = 0; i < numsSize; i++)
    {
        // get the number of characters in the int
        int numOfChars = to_string(nums[i]).length(); 
        if (numOfChars > longest)
        {
            longest = numOfChars;
        }
    }
    return longest;
}

//***********************************************************
// printOutput: method that prints the output of the program
// transactionLog: an array of transaction strings
// numTransactions: the size of the array
// beginningBalance: the beginning balance of the account
// numDeposits: the number of deposits made
// numWithdrawals: the number of withdrawals made
// monthlyInterestEarned: earned interest this month
// serviceCharges: service charges amount
// endingBalance: the ending balance of the account
// returns: nothing
//***********************************************************
void printOutput(string *transactionLog, int numTransactions, 
    double beginningBalance, double numDeposits, double numWithdrawals, 
    double monthlyInterestEarned, double serviceCharges,
    double endingBalance)
{

    // Prints the contents of the transaction log

    cout << "Transaction Log: " << endl;

    // if there are no transactions, tell the user
    if (numTransactions == 0)
    {
        cout << "No transactions were made this this month." << endl;
    }
    else
    {
        // print the contents of the transaction log
        // with a transaction number
        for (int i = 0; i < numTransactions; i++)
        {
            cout << "Transaction " << i + 1 << ": " 
                << transactionLog[i] << endl;
        }
    }
    cout << endl;



    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Monthly Starting Balance: " << beginningBalance << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << endl;
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Amount Deposited:         " << numDeposits << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << endl;
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Amount Withdrawn:         " << numWithdrawals << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << endl;
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Interest Earned:          " << monthlyInterestEarned << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << endl;
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Service Charges:          " << serviceCharges << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << endl;
    cout << "_._.__._.__._.__._.__._.__._.__._.__._.__._.__._._" << endl;
    cout << "| Monthly Ending Balance:   " << endingBalance << endl;
    cout << "-.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.--.-.-" << endl;
    cout << endl;
}

//***********************************************************
// main: method that runs the program
// argc: the number of command line arguments
// argv: the command line arguments
// returns: 0
//***********************************************************
int main(int argc, char const *argv[])
{
    printIntro();
    Account *account = getInput();
    int startingBalance = account->balance;
    cout << "Please input the number of deposits and withdrawals: ";
    int numDepositsAndWithdrawals; //
    cin >> numDepositsAndWithdrawals;
    cout << endl;
    // do transactions
    string *transactionLog = 
        doDepositsAndWithdrawals(account, numDepositsAndWithdrawals);
    account->monthlyProc();
    printOutput(transactionLog, numDepositsAndWithdrawals, startingBalance,
                account->amountDeposited, account->amountWithdrawn,
                account->monthlyInterestEarned, 
                account->amountServiceCharges,
                account->balance);
    delete account;
    delete[] transactionLog;
    return 0;
}
