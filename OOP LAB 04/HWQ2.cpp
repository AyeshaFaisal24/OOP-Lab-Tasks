#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            cerr << "Initial balance is invalid. Setting balance to 0." <<endl;
        }
    }

    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            std::cerr << "Invalid credit amount." << std::endl;
        }
    }
    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cerr << "Debit amount exceeded account balance or is invalid." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    Account myAccount(1000.0); 
    
    myAccount.credit(500.0);
    cout << "Balance after credit: " << myAccount.getBalance() << endl;
    
    myAccount.debit(300.0);
    cout << "Balance after debit: " << myAccount.getBalance() << endl;
    
    myAccount.debit(2000.0); 
    
    return 0;
}
