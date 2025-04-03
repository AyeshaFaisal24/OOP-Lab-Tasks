#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape {
    protected:
        string color;
        double x, y; 
        double borderThickness;

    public:
        Shape(string c, double xPos, double yPos, double thickness = 1.0)
            : color(c), x(xPos), y(yPos), borderThickness(thickness) {}

        virtual void draw() {
            cout << "Drawing a generic shape at (" << x << ", " << y << ")" << endl;
        }

        virtual double calculateArea() {
            return 0;
        }

        virtual double calculatePerimeter() {
            return 0;
        }

        void setColor(string c) { color = c; }
        string getColor() { return color; }
};

class Circle : public Shape {
    double radius;

    public:
        Circle(string c, double xPos, double yPos, double r, double thickness = 1.0)
            : Shape(c, xPos, yPos, thickness), radius(r) {}

        void draw() override {
            cout << "Drawing a " << color << " circle at (" << x << ", " << y 
                << ") with radius " << radius << endl;
        }

        double calculateArea() override {
            return 3.14159 * radius * radius;
        }

        double calculatePerimeter() override {
            return 2 * 3.14159 * radius;
        }
};

class Rectangle : public Shape {
    double width, height;

    public:
        Rectangle(string c, double xPos, double yPos, double w, double h, double thickness = 1.0)
            : Shape(c, xPos, yPos, thickness), width(w), height(h) {}

        void draw() override {
            cout << "Drawing a " << color << " rectangle at (" << x << ", " << y 
                << ") with width " << width << " and height " << height << endl;
        }

        double calculateArea() override {
            return width * height;
        }

        double calculatePerimeter() override {
            return 2 * (width + height);
        }
};

class Triangle : public Shape {
    double side1, side2, side3;

    public:
        Triangle(string c, double xPos, double yPos, double s1, double s2, double s3, double thickness = 1.0)
            : Shape(c, xPos, yPos, thickness), side1(s1), side2(s2), side3(s3) {}

        void draw() override {
            cout << "Drawing a " << color << " triangle at (" << x << ", " << y 
                << ") with sides " << side1 << ", " << side2 << ", " << side3 << endl;
        }

        double calculateArea() override {
            double s = (side1 + side2 + side3) / 2;
            return sqrt(s * (s - side1) * (s - side2) * (s - side3));
        }

        double calculatePerimeter() override {
            return side1 + side2 + side3;
        }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle("Red", 10, 10, 5);
    shapes[1] = new Rectangle("Blue", 20, 20, 8, 6);
    shapes[2] = new Triangle("Green", 30, 30, 3, 4, 5);

    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << endl << endl;
        delete shapes[i];
    }

    return 0;
}