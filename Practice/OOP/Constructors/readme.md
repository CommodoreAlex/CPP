# Constructor Types

A constructor is a special type of function that runs when an object is created. 

The types include:
- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Move Constructor
- Delegating Constructor
- Converting Constructor
- Explicit Constructor
- Destructor

---
##### 1. Default Constructor

Runs when you create an object with no arguments:
```cpp
struct A {
	A() {} // default constructor
};

A x;  // calls A()
```

If you do not define one the compiler may generate it automatically. It initializes data members using their own default constructors.

---
##### 2. Parameterized Constructor

Takes arguments to initialize the object:
```cpp
struct B {
	int n;
	B(int x) : n(x) {}
};

B b(10);  // calls B(int)
```

Using brace initialization you can give objects initial values.

---
##### 3. Copy Constructor

Creates a new object from an existing one:
```cpp
struct C {
	C(const C& other) {}
};

C c1;
C c2 = c1;  // calls copy constructor
```

Used when passing objects by value, returning objects by value (unless elided), or manually copying.

---
##### 4. Move Constructor

Introduced in C++11, it moves resources instead of copying them:
```cpp
struct D { 
	D(D&& other) {}
};

D make();
D d = make();  // calls move constructor (unless elided)
```

This is what makes modern C++ efficient with temporary objects.

---
##### 5. Delegating Constructor



---
##### 6. Converting Constructor



---
##### 7. Explicit Constructor



---
##### 8. Destructor



---
