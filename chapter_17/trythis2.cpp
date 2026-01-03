#include <iostream>
using namespace std;

class Shape {
public:
    Shape() { 
        cout << "Shape constructor\n"; 
    }

    virtual ~Shape() {    // virtual destructor
        cout << "Shape destructor\n"; 
    }

    virtual void draw() {
        cout << "Drawing Shape\n";
    }
};

class Circle : public Shape {
public:
    Circle() {
        cout << "Circle constructor\n";
    }

    ~Circle() override {
        cout << "Circle destructor\n";
    }

    void draw() override {
        cout << "Drawing Circle\n";
    }
};

class Square : public Shape {
public:
    Square() {
        cout << "Square constructor\n"; 
    }

    ~Square() override {
        cout << "Square destructor\n"; 
    }

    void draw() override {
        cout << "Drawing Square\n";
    }
};

int main() {

    cout << "\n--- 1. Objects created by value ---\n";
    {
        Circle c;
        Square s;
    } 


    cout << "\n--- 2. Base pointers to derived objects ---\n";
    {
        Shape* p1 = new Circle();
        Shape* p2 = new Square();

        delete p1;  
        delete p2;
    }

    cout << "\n--- 3. Base reference to derived object ---\n";
    {
        Circle c;
        Shape& ref = c;
    } // c is destroyed here

    cout << "\n--- END OF PROGRAM ---\n";
}
