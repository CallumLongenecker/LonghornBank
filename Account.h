using namespace std;

class Account {
    public:
        double balance; // double to store the balance for this account
        int numDeposits; // stores the number of deposits this month for this account
        int numWithdrawals; // stores the number of withdrawals this month for this account
        double annualInterest; // stores the annual interest rate for this account
        double monthlyServiceCharges; // stores the monthly service charges for this account
    
        Account(double initBalance, double initAnnualInterest);
        virtual void deposit(double amt);
        virtual void withdraw(double amt);
        virtual void calcInt();
        virtual void monthlyProc();
};

class Savings : public Account {
    private:
        double monthlyInterest; // stores the monthly interest rate for this account
        bool status; // stores the status of this account, true if active, false if inactive
    public:
        void deposit(double amt);
        void withdraw(double amt);
        void monthlyProc();

};

class Checking : public Account {
    private:
        double monthlyInterest; // stores the monthly interest rate for this account
        double serviceCharges; // stores the monthly service charges for this account
        
    public:
        void deposit(double amt);
        void withdraw(double amt);
        void calcInt();
        void monthlyProc();
};
