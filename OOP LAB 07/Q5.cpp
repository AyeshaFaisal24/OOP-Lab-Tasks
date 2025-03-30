#include <iostream>
using namespace std;

class Shape{
    float area;

    public:
        Shape(float a) : area(a) {}

        Shape operator+(const Shape& other){
            return Shape(area + other.area);
        }

        void display(){
            cout << area << endl;
        }
};

int main(){
    Shape shape1(8);
    Shape shape2(4);

    Shape shape3 = shape1 + shape2;
    shape3.display();

    return 0;
}