#include "linalg.hpp"
#include <iostream>

int main() {
  LinAlg::Vec3 a{1, 2, 3};
  LinAlg::Vec3 b{4, 5, 6};
  LinAlg::Vec2 c{0, 0};
  std::cout << "c = " << c << std::endl;
  std::cout << "a + b = " << (a + b) << std::endl;
  std::cout << "dot = " << a.dot(b) << std::endl;
  std::cout << "cross = " << a.cross(b) << std::endl;
  std::cout << "len(a) = " << a.length() << std::endl;
}
