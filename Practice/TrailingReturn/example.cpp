#include <iostream>
#include <string>

// If you want to be explicit about return type, you can use trailing return type specification
// when you return a string literal for example

int main() {

  // Setting the return type to std::string
  auto testSpeedString = [](int speed) -> std::string {
    if (speed > 100)
      return "you're a super fast";
    return "you're a regular";
  };

  auto str = testSpeedString(100);

  str += " driver";

  std::cout << str;

  return 0;
}
