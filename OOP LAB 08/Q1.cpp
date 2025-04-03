#include <iostream>
#include <string>
using namespace std;

class Account {
    protected:
        string accountNumber;
        string accountHolderName;
        string accountType;
        double balance;

    public:
        Account(string num, string name, string type, double bal)
            : accountNumber(num), accountHolderName(name), accountType(type), balance(bal) {}

        virtual void deposit(double amount) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        }

        virtual void withdraw(double amount) {
            if (amount > balance) {
                cout << "Insufficient funds!" << endl;
            } else {
                balance -= amount;
                cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
            }
        }

        virtual double calculateInterest() {
            return 0; // Base account has no interest
        }

        virtual void printStatement() {
            cout << "Account Statement for " << accountNumber << endl;
            cout << "Holder: " << accountHolderName << endl;
            cout << "Type: " << accountType << endl;
            cout << "Balance: $" << balance << endl;
        }

        void getAccountInfo() {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Holder Name: " << accountHolderName << endl;
            cout << "Type: " << accountType << endl;
            cout << "Balance: $" << balance << endl;
        }
};

class SavingsAccount : public Account {
    double interestRate;
    double minimumBalance;

    public:
        SavingsAccount(string num, string name, double bal, double rate, double minBal)
            : Account(num, name, "Savings", bal), interestRate(rate), minimumBalance(minBal) {}

        void withdraw(double amount) override {
            if (balance - amount < minimumBalance) {
                cout << "Cannot withdraw. Minimum balance requirement not met." << endl;
            } else {
                Account::withdraw(amount);
            }
        }

        double calculateInterest() override {
            double interest = balance * interestRate / 100;
            balance += interest;
            return interest;
        }

        void printStatement() override {
            Account::printStatement();
            cout << "Interest Rate: " << interestRate << "%" << endl;
            cout << "Minimum Balance: $" << minimumBalance << endl;
        }
};

class FixedDepositAccount : public Account {
    string maturityDate;
    double fixedInterestRate;

    public:
        FixedDepositAccount(string num, string name, double bal, string date, double rate)
            : Account(num, name, "Fixed Deposit", bal), maturityDate(date), fixedInterestRate(rate) {}

        void withdraw(double amount) override {
            cout << "Cannot withdraw from Fixed Deposit before maturity date: " << maturityDate << endl;
        }

        double calculateInterest() override {
            double interest = balance * fixedInterestRate / 100;
            balance += interest;
            return interest;
        }

        void printStatement() override {
            Account::printStatement();
            cout << "Maturity Date: " << maturityDate << endl;
            cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
        }
};

int main() {
    Account* acc1 = new SavingsAccount("SAV123", "Ali Khan", 1000, 2.5, 500);
    Account* acc2 = new FixedDepositAccount("FD456", "Clara Sid", 5000, "2025-12-31", 5.0);

    acc1->deposit(200);
    acc1->withdraw(300);
    acc1->withdraw(400); // Should fail due to minimum balance
    acc1->calculateInterest();
    acc1->printStatement();

    cout << endl;

    acc2->withdraw(1000); // Should fail - fixed deposit
    acc2->calculateInterest();
    acc2->printStatement();

    delete acc1;
    delete acc2;
    return 0;
}