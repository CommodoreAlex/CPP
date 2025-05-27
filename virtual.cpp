#include <iostream>
using namespace std;

// Base Class
class Animal {
public:
    virtual void makeSound() { // Virtual function
        cout << "Some generic animal sound" << endl;
    }
};

// Derived Class
class Dog : public Animal {
public:
    void makeSound() override { // Overrides the base function
        cout << "Bark!" << endl;
    }
};

int main() {
    Animal* ptr;
    Dog d;
    ptr = &d;
    ptr->makeSound(); // Calls Dog's overriden function (Output: Bark!)

    return 0;
}
