#include <boost/shared_ptr.hpp>
#include <iostream>

// Avoids manual memory management, frees memory when unused
void demo() {
    boost::shared_ptr<int> ptr(new int(42));
    std::cout << "Value: " << *ptr << std::endl;
}

int main() {
    demo();
    return 0;
}
