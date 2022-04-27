#include <iostream>
#include <string>

using namespace std;

int num_transactions = 0;

int main(int argc, char const *argv[])
{
    cout << "Please choose whether or not "
    return 0;
}

void printOutput(string *transaction_log, double beginning_balance, double amount_deposits, double amount_withdrawals, double interest, double service_charges, double ending_balance){
    // Prints the contents of the transaction log
    cout << "Transaction Log: " << endl;
    for (int i = 0; i < num_transactions; i++){
        cout << transaction_log[i] << endl;
    }

    //print the remaining end of month statistics
    cout << "Beginning Balance: " << beginning_balance << endl;
    cout << "Amount Deposited: " << amount_deposits << endl;
    cout << "Amount Withdrawn: " << amount_withdrawals << endl;
    cout << "Interest Earned: " << interest << endl;
    cout << "Service Charges: " << service_charges << endl;
    cout << "Ending Balance: " << ending_balance << endl;

}

