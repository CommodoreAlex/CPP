#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
  std::string name;
  int age;
};

std::vector<Person> people = {
  {"Alice", 30},
  {"Bob", 20},
  {"Charlie", 25}
};

int main() {

  std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) { return a.age < b.age; });

  for ( const auto& p : people) {
    std::cout << p.name << " (" << p.age << ")\n";
  }
  
  return 0;
}



