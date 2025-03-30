#include <iostream>
using namespace std;

class Person {
    int ID;  

public:
    Person() : ID(0) {}

    void getData() {
        cout << "Enter Employee ID: ";
        cin >> ID;
    }

    void displayData() {
        cout << "Employee ID: " << ID << endl;
    }
};

class Admin : public Person {
    string name;
    double monthlyIncome;

public:
    Admin() : name("unknown"), monthlyIncome(0.0) {}

    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore();  
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void bonus() {
        double annualBonus = (monthlyIncome * 12) * 0.05; 
        cout << "Bonus: " << annualBonus << endl;
    }

    void displayData() {
        Person::displayData(); 
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        bonus();
    }
};

class Accounts : public Person {
protected:
    string name;
    double monthlyIncome;

public:
    Accounts() : name(""), monthlyIncome(0.0) {}

    void getData() {
        Person::getData(); 
        cout << "Enter Name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void bonus() {
        double annualBonus = (monthlyIncome * 12) * 0.05; 
        cout << "Bonus: " << annualBonus << endl;
    }

    void displayData() {
        Person::displayData();  
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        bonus();
    }
};

int main() {
    Admin admin;
    Accounts accounts;

    cout << "Enter Admin Employee Details:" << endl;
    admin.getData();  

    cout << endl;

    cout << "Enter Accounts Employee Details:" << endl;
    accounts.getData();  

    cout << endl;

    cout << "Admin Employee Information:" << endl;
    admin.displayData();

    cout << endl;

    cout << "Accounts Employee Information:" << endl;
    accounts.displayData();

    return 0;
}
