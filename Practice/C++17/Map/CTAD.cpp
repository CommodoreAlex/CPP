#include <iostream>
#include <map>

int main() {

  std::map<std::string, int> mapUsersAge { {"Alex", 45}, {"John", 25} };

  // Class Template Argument Deducation (CTAD)
  std::map mapCopy{mapUsersAge};

  if (auto [iter, wasAdded] = mapCopy.insert_or_assign("John", 26); !wasAdded) std::cout << iter->first << " reassigned...\n";

  for (const auto& [key, value] : mapCopy) {
    std::cout << key << ", " << value << '\n';
  }

}
