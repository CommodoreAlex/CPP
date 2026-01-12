#include <iostream>
#include <map>

int main() {

  std::map<std::string, int> mapUsersAge { {"Alex", 45}, {"John", 25} };

  // Class Template Argument Deducation (CTAD)
  std::map mapCopy{mapUsersAge};

  // If the key does not exist, it inserts it and returns {iterator,true}
  // If the key already exists, it assigns the new value and returns {iterator,false}
  // Structured binding unpacks the pair returned by insert_or_assign
  if (auto [iter, wasAdded] = mapCopy.insert_or_assign("John", 26); !wasAdded) std::cout << iter->first << " reassigned...\n";

  // Structured Binding [key, value]
  for (const auto& [key, value] : mapCopy) {
    std::cout << key << ", " << value << '\n';
  }

}
