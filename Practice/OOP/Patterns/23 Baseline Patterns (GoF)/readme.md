# Virtual Tables (VTABLES) in OOP

The Virtual Table (vtable):
- This is an internal lookup table created by the compiler whenever a class has at least one virtual function.

This matters in object-oriented programming because it enables polymorphism "ability to interpret objects based on context", allows safe deletion through base pointers, and support plugin-like-architectures.

The cost associated is one pointer per object (vptr), one vtable per class, and there is overhead for dynamic dispatch.

A class gets a vtable when:
- It declares at least one virtual function
- It inherits from a class with virtual functions

---

When you call a virtual function:
1. The program looks up the object's VPTR (virtual function pointer)
2. Follows it to the vtable
3. Finds the correct function pointer
4. Calls the function belonging to the actual object type

This is how C++ achieves runtime polymorphism.
