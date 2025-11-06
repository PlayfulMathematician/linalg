#include <array>
#include <cmath>
#include <iostream>
namespace LinAlg {
template <int N> class Vector {
public:
  std::array<double, N> elements = {};
  Vector<N> operator+(const Vector<N> &rhs) const;
  Vector<N> operator-(const Vector<N> &rhs) const;
  Vector<N> &operator+=(const Vector<N> &rhs);
  Vector<N> &operator-=(const Vector<N> &rhs);
  double length() const;
  Vector<N> operator*(double n) const;
  double dot(const Vector<N> &rhs) const;
  Vector<3> cross(const Vector<3> &rhs) const;
  double &operator[](std::size_t i) { return elements[i]; }
  const double &operator[](std::size_t i) const { return elements[i]; }
};

template <int N> Vector<N> Vector<N>::operator+(const Vector<N> &rhs) const {
  Vector<N> result;
  for (int i = 0; i < N; i++) {
    result[i] = (*this)[i] + rhs[i];
  }
  return result;
}

template <int N> Vector<N> Vector<N>::operator-(const Vector<N> &rhs) const {
  Vector<N> result;
  for (int i = 0; i < N; i++) {
    result[i] = (*this)[i] - rhs[i];
  }
  return result;
}

template <int N> Vector<N> Vector<N>::operator*(double n) const {
  Vector<N> result;
  for (int i = 0; i < N; i++) {
    result[i] = (*this)[i] * n;
  }
  return result;
}

template <int N> Vector<N> operator*(double n, const Vector<N> &v) {
  return v * n;
}

template <int N> Vector<N> &Vector<N>::operator+=(const Vector<N> &rhs) {
  for (int i = 0; i < N; i++) {
    elements[i] += rhs[i];
  }
  return *this;
}

template <int N> Vector<N> &Vector<N>::operator-=(const Vector<N> &rhs) {
  for (int i = 0; i < N; i++) {
    elements[i] -= rhs[i];
  }
  return *this;
}

template <int N> double Vector<N>::dot(const Vector<N> &rhs) const {
  double dot = 0;
  for (int i = 0; i < N; i++) {
    dot += (*this)[i] * rhs[i];
  }
  return dot;
}

template <int N>
std::ostream &operator<<(std::ostream &os, const Vector<N> &p) {
  os << "(";
  for (int i = 0; i < N - 1; i++) {
    os << p[i] << ", ";
  }
  os << p[N - 1] << ")";
  return os;
}
template <int N> double Vector<N>::length() const {
  return std::sqrt(dot(*this));
}
template <> Vector<3> Vector<3>::cross(const Vector<3> &rhs) const {
  return Vector<3>{{elements[1] * rhs[2] - elements[2] * rhs[1],
                    elements[2] * rhs[0] - elements[0] * rhs[2],
                    elements[0] * rhs[1] - elements[1] * rhs[0]}};
}
using Vec3 = Vector<3>;
using Vec2 = Vector<2>;

} // namespace LinAlg
int main() {

  LinAlg::Vector<2> a;
  LinAlg::Vector<2> b;
  std::cout << "Welcome to my Vector library!" << std::endl;
  std::cout << "Input the x coordinate of the first vector: ";
  std::cin >> a[0];
  std::cout << "Input the y coordinate of the first vector: ";
  std::cin >> a[1];
  std::cout << "Input the x coordinate of the second vector: ";
  std::cin >> b[0];
  std::cout << "Input the y coordinate of the second vector: ";
  std::cin >> b[1];

  std::cout << "a = " << a << "\n";
  std::cout << "b = " << b << "\n";
  std::cout << "a + b = " << a + b << "\n";
  std::cout << "a - b = " << a - b << "\n";
  std::cout << "a * 2 = " << a * 2 << "\n";
  std::cout << "Dot(a, b) = " << a.dot(b) << "\n";
}
