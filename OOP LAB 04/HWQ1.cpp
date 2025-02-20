#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
    const double PI = 3.14159;

public:
    Circle(double r){
      radius = r;
    }

    double getArea() const {
        return PI * radius * radius;
    }

    double getPerimeter() const {
        return 2 * PI * radius;
    }
};

int main() {
    Circle C(8.0); 
    
    cout << "Area: " << C.getArea() << endl;
    cout << "Perimeter: " << C.getPerimeter() << endl;
    
    return 0;
}