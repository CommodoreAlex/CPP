The factory method defines an interface for creating an object, but lets subclasses decide which concrete class to instantiate, helping you avoid hard-coding `new` everywhere.

----

You use this method when you want to:
1. Delegate object creation to subclasses
2. Avoid `switch` or `if` chains deciding which class to create
3. You want to follow the Open/Closed principle.

An example scenario, imagine a game where different enemies spawn, you can let subclasses decide what to do.

When your program needs to create different kinds of objects, beginners typically do this:
```cpp
if (type == "orc") return new Orc();
else if (type == "troll") return new Troll();
```

The "Factory Method" pattern solves for this problem by moving object creation into separate classes, so your main code never needs to know the exact type being created.

---
# Implementation

The Factory Method has the same four parts:
1. **Product Interface:** Defines what all created objects must be able to do.
2. **Concrete Products:** These are the actual objects created.
3. **Factory Interface:** This defines the function that creates objects.
4. **Concrete Factories:** These are the classes that actually create the objects.

Example:
```cpp
#include <iostream>

// Product Interface
class Enemy {
public:
  // Designed to be overridden in derived classes (virtual)
  virtual void attack() = 0;
  virtual ~Enemy() = default; // virtual + compiler-generated
};

// Concrete Products
class Orc : public Enemy {
public:
  void attack() override {
    std::cout << "Xyz Action\n";
  }
};

class Troll : public Enemy {
public:
  void attack() override {
    std::cout << "YZ Action\n";
  }
};

// A Factory Interface
class EnemyFactory {
public:
  virtual Enemy* createEnemy() = 0;
  virtual ~EnemyFactory() = default;
};

// Concrete Factories
class OrcFactory : public EnemyFactory {
public:
  Enemy* createEnemy() override {
    return new Orc();
  }
};

class TrollFactory : public EnemyFactory {
public:
  Enemy* createEnemy() override {
    return new Troll();
  }
};

// Client Code
void spawnEnemy(EnemyFactory& factory) {
  Enemy* e = factory.createEnemy();
  e->attack();
  delete e;
}

int main() {
  OrcFactory orcFactory;
  TrollFactory trollFactory;
  
  spawnEnemy(orcFactory);
  spawnEnemy(trollFactory);
  return 0;
}
```

---
