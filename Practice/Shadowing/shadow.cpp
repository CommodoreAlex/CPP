#include <iostream>

class Foo {
public:
  int value = 0;

  void setValue(int value) {
    // The parameter 'value' SHADOWS the member 'value'
    this->value = value;  // left = member, right = parameter
  }

  void setValue(int newValue) {
    value = newValue; // no shadowing, no need for this->
  }


  // Shadowing with local variables
  int count = 5;

  void doSomething() {
    int count = 10;
    std::cout << count << "\n";       // prints 10 (local)
    std::cout << this->count << "\n"; // prints 5 (member)
  }
};

class Point {
public:
  int x, y;

  // Shadowing with constructors
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
};
