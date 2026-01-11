#include <concepts>
#include <iostream>

template <typename T>
concept IRenderable = requires(T v) {
  { v.render() } -> std::same_as<void>;
  { v.getVertCount() } -> std::convertible_to<size_t>;
};

struct Circle {
  void render() { std::cout << "drawing circle\n"; }
  size_t getVertCount() const { return 10; };
};

struct Square {
  void render() { std::cout << "drawning square\n"; }
  size_t getVertCount() const { return 4; };
};

int main() {
  const auto RenderCaller = [](IRenderable auto &obj) {
    obj.render();
  };

  Circle c;
  RenderCaller(c);
  Square s;
  RenderCaller(s);
}
