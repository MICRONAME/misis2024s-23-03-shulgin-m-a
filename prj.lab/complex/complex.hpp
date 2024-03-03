#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iosfwd>
#include <limits>
#include <cmath>

struct Complex {
  [[nodiscard]] Complex() = default;
  [[nodiscard]] explicit Complex(const double real) : re(real), im(0) {}
  [[nodiscard]] Complex(const double real, const double imaginary) : re(real), im(imaginary) {}
  [[nodiscard]] Complex(const Complex& rhs) = default;
  ~Complex() = default;

  Complex operator- () const noexcept { return Complex(-re, -im); }

  Complex& operator= (const Complex rhs);
  Complex& operator= (const double rhs);
  Complex& operator+= (const Complex rhs);
  Complex& operator+= (const double rhs);
  Complex& operator-= (const Complex rhs);
  Complex& operator-= (const double rhs);
  Complex& operator*= (const Complex rhs);
  Complex& operator*= (const double rhs);
  Complex& operator/= (const Complex rhs);
  Complex& operator/= (const double rhs);

  bool operator== (const Complex rhs) const;
  bool operator== (const double rhs) const;
  bool operator!= (const Complex rhs) const;
  bool operator!= (const double rhs) const;

  std::ostream& WriteTo(std::ostream& stream) const;
  std::istream& ReadFrom(std::istream& stream);

  void conjugate();

  double re = 0;
  double im = 0;
  static const char leftBrace{ '{' };
  static const char separator{ ',' };
  static const char rightBrace{ '}' };
  const double minDiff = 2 * std::numeric_limits<double>::epsilon();
};

Complex operator+ (const Complex lhs, const Complex rhs);
Complex operator+ (const Complex lhs, const double rhs);
Complex operator+ (const double lhs, const Complex rhs);
Complex operator- (const Complex lhs, const Complex rhs);
Complex operator- (const Complex lhs, const double rhs);
Complex operator- (const double lhs, const Complex rhs);
Complex operator* (const Complex lhs, const Complex rhs);
Complex operator* (const Complex lhs, const double rhs);
Complex operator* (const double lhs, const Complex rhs);
Complex operator/ (const Complex lhs, const Complex rhs);
Complex operator/ (const Complex lhs, const double rhs);
Complex operator/ (const double lhs, const Complex rhs);

std::istream& operator>> (std::istream& stream, Complex& val);
std::ostream& operator<< (std::ostream& stream, const Complex val);

#endif