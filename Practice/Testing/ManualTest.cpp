#include <iostream>

int add(int a, int b) {
  return a + b;
}

// UNIT TEST FUNCTION: add() function
void test_add() {

  // Struct Type to hold one test case
  struct TestCase {
    int a, b, expected;
  };

  // Array of test cases
  TestCase cases[] = {
    {1, 2, 3},
    {-1, 5, 4},
    {0, 2, 0}
  };

  // Call the function we're testing and appends to result for comparison
  for (auto& tc : cases) {
    int result = add(tc.a, tc.b); 
    if(result == tc.expected) {
      std::cout << "PASS: add(" << tc.a  << ", " << tc.b << ")\n";
    } else {
      std::cout << "FAIL: add(" << tc.a << ", " << tc.b
                << ") expected " << tc.expected
                << " but got " << result << "\n";
    }
  }
}

int main() {
  test_add();
}
