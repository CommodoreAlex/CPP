# Atomics in C++

### Atomic Load and Store

The simplest type of atomic operations:
```cpp
std::atomic<int> value{0};

value.store(10);      // atomic write
int x = value.load(); // atomic read
```

`store()` writes a value atomically
`load()` reads a value atomically

This solves for a critical section with no mutex needed; provided you are doing a limited set of concurrent operations.

---

### Atomic Increment / Decrement

Short-hand for fetch-add and fetch-sub:
```cpp
std::atomic<int> counter{0};

counter++;
counter--;
```

These are safe even with many threads hammering the same variable.

---

### Fetch Add / Fetch Sub

These return the old value before modification (e.g. pre increment):
```cpp
std::atomic<int> counter{5};

int old = counter.fetch_add(3);  // old = 5, counter becomes 8
```

This helps when you need the previous value (e.g. assigning unique IDs)/

---

### Exchange()

Atomically replaces the value and returns the old one:
```cpp
std::atomic<int> flag{0};

int old = flag.exchange(1);  // flag becomes 1, old gets previous value
```

Useful for implementing spinlocks or toggles.

----

### Compare_Exchange_Strong/Weak

This is the most powerful atomic operation.
```cpp
std::atomic<int> value{10};

int expected = 10;
bool success = value.compare_exchange_strong(expected, 20);
```

If `value == expected`, set `value = 20` and return true - otherwise, set `expected` to the current value and return false.

This is the foundation of a lock-free algorithm.

---

### Atomic Flags

A specialized atomic boolean with test and set semantics:
```cpp
std::atomic_flag lock = ATOMIC_FLAG_INIT;

if(!lock.test_and_set()) {
	// acquired the flag
}
lock.clear();
```

This is the building block of spinlocks.

---

### Memory Order 

Every atomic operation can specify a memory order:
```cpp
value.store(10, std::memory_order_release);
int x = value.load(std::memory_order_acquire);
```

---
