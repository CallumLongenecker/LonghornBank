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
#include <sstream>
#include "Savings.h"
#include "Checking.h"
using namespace std;


//***********************************************************
// dollar: method to append a dollar sign in front of double 
// and return resulting string
// num: double to append dollar sign to
// returns: string with dollar sign in front of num
//***********************************************************
string dollar(double num)
{
   stringstream ss;
   ss << fixed << setprecision(2) << num;
   string numString = ss.str();
   // append dollar sign
   numString.insert(0, "$");
   return numString;
}

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
        // ask the user if they want to make a deposit or withdrawal
         cout << "Would you like to make a deposit or withdrawal?" 
            << " (D = Deposit, W = Withdrawal): ";
         char depositOrWithdrawal = 'a';
         // make sure user only inputs D or W
         while(depositOrWithdrawal != 'D' && depositOrWithdrawal != 'W')
         {
            cin >> depositOrWithdrawal;

            depositOrWithdrawal = toupper(depositOrWithdrawal);
            if (depositOrWithdrawal != 'D' && depositOrWithdrawal != 'W')
            {
                cout << "Invalid input. Please try again: ";
            }
         }

        // ask the user for the amount of the deposit or withdrawal
        cout << "Please input the amount of the deposit or withdrawal: $";
        double amount;
        cin >> amount;
        cout << endl;

        // make the deposit or withradrawal
        if (depositOrWithdrawal == 'D')
        {
            // make the deposit
            result[i] = "Deposit of " + dollar(amount) + " made.";
            account->deposit(amount);
        }
        else if (depositOrWithdrawal == 'W')
        {
            // make a withdrawal
            if (account->withdraw(amount))
            {
                result[i] = "Withdrawal of " + dollar(amount) 
                    + " made.";
            }
            else
            {
                result[i] = "Withdrawal of " + dollar(amount) 
                    + " failed.";
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
   // get the user input and error check
   cout << "Please choose your account type (S = Savings, C = Checking): ";
   char accountType = 'a';
   while(accountType != 'S' && accountType != 'C')
   {
       cin >> accountType;

       accountType = toupper(accountType);
       if (accountType != 'S' && accountType != 'C')
       {
           cout << "Invalid account type. Please try again: ";
       }
   }

   string accountTypeString;
   if (accountType == 'S')
   {
       accountTypeString = "Savings";
   }
   else
   {
       accountTypeString = "Checking";
   }

    double initBal, initInterestRate;
    cout << endl;
    cout << "Please input your " << accountTypeString 
      << " account's beginning balance: $";
    cin >> initBal;
    cout << "Please input your " << accountTypeString 
      << " account's annual interest rate percentage: ";
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
    cout << "        | ... |_._._._._._._._._._._| ... |\n";
    cout << "        | ||| |  o LONGHORN BANK o  | ||| |\n";
    cout << "        | \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |\n";
    cout << "   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n";
    cout << "  (())) |     |---------------------|     | (()))\n";
    cout << " (())())| \"\"\" |  \"\"\"   " 
        << " \"\"\"    \"\"\"  | \"\"\" |(())())\n";
    cout << " (()))()|[-|-]|  :::   .-\"-.   :::  |[-|-]|(()))())\n";
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

    cout << "  " 
        << "____                                         ____\n";
    cout << "     " 
        << "/                                         \\\n";
    cout << "     " 
        << "(__________________________________________)\n";
    cout << "                         (oo)\n";
    cout << "                  /-------\\/          \n";
    cout << "                 / |     ||          \n";
    cout << "                *  ||----||            \n";
    cout << "                  " 
        << " ~~    ~~                 \n";
    cout << endl;
    cout << "                Have a nice day!" << endl;
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

    cout << "888                        888" << endl;
    cout << "888                        888" << endl;
    cout << "888                        888" << endl;
    cout << "888 .d88b. 88888b.  .d88b. 88888b. " 
        << " .d88b. 888d88888888b." << endl;
    cout << "888d88\"\"88b888 \"88bd88P\"88b888 " 
        << "\"88bd88\"\"88b888P\"  888 \"88b" << endl;
    cout << "888888  888888  888888  888888 "
        << " 888888  888888    888  888" << endl;
    cout << "888Y88..88P888  888Y88b 888888 " 
        << " 888Y88..88P888    888  888" << endl;
    cout << "888 \"Y88P\" 888  888 \"Y88888888 " 
        << " 888 \"Y88P\" 888    888  888 " << endl;
    cout << "                           888" << endl;
    cout << "                      Y8b d88P" << endl;
    cout << "                       \"Y88P\"" << endl;
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
// amountDeposited: the amount of deposits made
// amountWithdrawn: the amount of withdrawals made
// monthlyInterestEarned: earned interest this month
// serviceCharges: service charges amount
// endingBalance: the ending balance of the account
// returns: nothing
//***********************************************************
void printOutput(string *transactionLog, int numTransactions, 
    double beginningBalance, double amountDeposited, double amountWithdrawn, 
    double monthlyInterestEarned, double serviceCharges,
    double endingBalance)
{
      // bank logo
      printLogo();

    // Prints the contents of the transaction log

    cout << "Transaction Log: " << endl;
    cout << "-----------------------------------------------------" << endl;

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

      

    cout << "_____________________________________________________" << endl;
    cout << "| Monthly Starting Balance: " << setw(24) << right 
      << dollar(beginningBalance) << "|" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
    cout << "_____________________________________________________" << endl;
    cout << "| Amount Deposited:         " << setw(24) << right 
      << dollar(amountDeposited) << "|" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
    cout << "_____________________________________________________" << endl;
    cout << "| Amount Withdrawn:         " << setw(24) << right 
      << dollar(amountWithdrawn) << "|" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
    cout << "_____________________________________________________" << endl;
    cout << "| Interest Earned:          " << setw(24) << right 
      << dollar(monthlyInterestEarned) << "|" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
    cout << "_____________________________________________________" << endl;
    cout << "| Service Charges:          " << setw(24) << right 
      << dollar(serviceCharges) << "|" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
    cout << "_____________________________________________________" << endl;
    cout << "| Monthly Ending Balance:   " << setw(24) << right 
      << dollar(endingBalance) << "|" << endl;
    cout << "-----------------------------------------------------" << endl;
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
    printCow();
    return 0;
}
