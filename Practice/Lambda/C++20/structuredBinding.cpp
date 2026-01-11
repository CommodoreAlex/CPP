#include <tuple>
#include <string>

auto GetParams() {
  return std::tuple { std::string{"Hello World"}, 42};
}

int main() {
  auto [x, y] = GetParams();
  const auto ParamLength = [&x, &y]() { return x.length() + y; }();
  return ParamLength;
}
