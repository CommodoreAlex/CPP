# Singleton OOP Pattern Description
---

Definition - "A Singleton is a class in C++ that ensures only one instance ever exists and provides global access to that instance."

A singleton is a class designed so that:
1. Only one instance of the class can ever exist
2. You can access that instance globally
3. The class controls its own lifetime

In other words, a singleton is a globally accessible object with exactly one instance.

The typical use cases include a logging system, configuration manager, resource manager (textures, audio, etc), database connection, or global registry.

Anything where "there should only be one of these" makes sense.

Pros to Singletons:
1. Easy global access
2. Controlled lifetime
3. Only one instance
4. Simple to use

Cons to Singletons:
1. Can hide dependencies
2. Harder to test (global state)
3. Can lead to tight coupling
4. Overused in beginner code

---
The Classic C++ Singleton Pattern
--

The simplest thread-safe version (C++11 and later):
```cpp
class Singleton {
public:
	static Singleton& instance() {
		static Singleton inst;  // created once, guaranteed thread-safe
		return inst;
	}
	
	void doSomething() {
		// ...
	}
	
private:
	Singleton() = default;                            // private constructor
	Singleton(const Singleton&) = delete;             // no copying
	Singleton& operator=(const Singleton&) = delete;  // no assignment
};
```

Using it:
```cpp
Singleton::instance().doSomething();
```

---

The private constructor prevents anyone from doing:
```cpp
Singleton s;                   // not allowed
Singleton* p = new Singleton;  // not allowed
```

The deleted copy / move operations prevent duplication.

Static local variable in C++11 guarantees that:
1. It is created once
2. It is destroyed automatically at program end
3. Initialization is thread-safe

This is the modern, correct way to implement a singleton.

---
