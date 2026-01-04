#include <iostream>
#include <memory>

int main() {

  std::unique_ptr<int> p(new int{10});

  const auto bar = [ptr=std::move(p)] {
    std::cout << "pointer in lambda: " << ptr.get() << '\n';
  };

  std::cout << "pointer in main(): " << p.get() << '\n';
  bar();

  return 0;
}
