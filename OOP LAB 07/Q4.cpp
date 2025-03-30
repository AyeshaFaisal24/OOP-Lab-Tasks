#include <iostream>
using namespace std;

class Decrement {
    int value;

    public:
        Decrement(int v) : value(v) {}

        // Prefix Decrement: Multiplies value by 4
        Decrement operator--() {
            value *= 4;
            return *this;
        }

        // Postfix Decrement: Divides value by 4
        Decrement operator--(int) {
            Decrement temp = *this; 
            value /= 4;
            return temp;
        }

        void display() {
            cout << "Value: " << value << endl;
        }
};

int main() {
    Decrement d(8);

    --d;
    d.display();

    d--;
    d.display(); 

    return 0;
}
