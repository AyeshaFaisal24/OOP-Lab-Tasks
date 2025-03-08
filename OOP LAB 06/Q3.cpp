#include <iostream>
using namespace std;

class Employee{           //Base class for chef,waiter and cashier
    protected:
        int ID;
        string name;

    public:
        Employee (int id , string n) : ID(id) , name(n) {}

        virtual void OrderTaker () {                 // Virtual function to take orders (overridden in Waiter & Manager)
            cout << "Order Taken!!" << endl;
        }

        virtual void OrderPreparer () {       // Virtual function to prepare orders (overridden in Chef)
            cout << "Order Preparing!!" << endl;
        }

        virtual void Biller () {           // Virtual function for billing (overridden in Cashier & Manager)
            cout << "Billing Done!!" << endl;
        }

        virtual ~Employee() {}
};

class Waiter : virtual public Employee {     //child class of employee (hierchial inheritance)
    public:
        Waiter (int id , string n) : Employee(id,n) {}

        void OrderTaker () override {
            cout << name << " (waiter) is taking the order." << endl;
        }
};

class Chef :virtual public Employee {       //child class of employee  (hierchial inheritance)
    public:
        Chef (int id , string n) : Employee(id,n) {}

        void OrderPreparer() override {
            cout << name << " (Chef) is preparing the food." << endl;
        }
};

class Cashier : virtual public Employee{       //child class of employee   (hierchial inheritance)
    public:
       Cashier(int id , string n) : Employee(id,n) {};

       void OrderPreparer() override {
            cout << name << " (Chef) is preparing the food." << endl;
        }
};

class Manager : public Waiter , public Cashier {          //child class of both waiter and cashier(multiple inheritance and diamond under employee)
    public:
       Manager (int id , string n) : Employee(id,n) , Waiter(id,n) , Cashier(id,n) {}

        void OrderTaker() override {
            cout << name << " (Manager) is overseeing order-taking." << endl;
        }

        void Biller() override {
            cout << name << " (Manager) is handling billing and finance." << endl;
        }
};

class Menu{
    protected:
       int itemID;
       int itemNum;

    public:
       Menu (int id , int num) : itemID(id) , itemNum(num) {}

       virtual void calculateCost(int n) = 0;
};

class FoodMenu :public Menu {
    public:
      FoodMenu(int id , int num) : Menu(id,num) {}

      void calculateCost (int n) override {
        int cost = n * 30;
        cout << "Total Cost of " << n << " items:" << cost << endl;
    }
};

class BeveragesMenu :public Menu {
    public:
       BeveragesMenu(int id , int num) : Menu(id,num){}

       void calculateCost (int n) {
           int cost = n * 20;
           cout << "Total Cost of " << n << " beverages:" << cost << endl;
       }
};

int main() {
    Employee* e1 = new Waiter(101, "John");
    Employee* e2 = new Chef(102, "Sarah");
    Employee* e3 = new Cashier(103, "David");
    Employee* e4 = new Manager(104, "Alice");

    e1->OrderTaker();       //Calling overridden functions 
    e2->OrderPreparer();
    e3->Biller();
    e4->OrderTaker();
    e4->Biller();

    delete e1;
    delete e2;
    delete e3;
    delete e4;

    cout << endl;

    FoodMenu food(1, 2);
    food.calculateCost(3);

    BeveragesMenu drink(2, 3);
    drink.calculateCost(4);

    return 0;
}