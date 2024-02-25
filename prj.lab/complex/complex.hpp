#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <sstream>
#include <limits>

struct Complex
{
  ///CONSTRUCTOR
  Complex() = default;
  Complex(const Complex&) = default;
  explicit Complex(double real) : re(real) {};
  Complex(double real, double imaginary) : re(real), im(imaginary) {};

  /// ASSIGNING
  Complex& operator=(const Complex rhs);

  /// UNARY MINUS
  Complex operator-() const noexcept;

  ///EQUALITY CHECK
  bool operator==(const Complex rhs) const { return (std::abs(re - rhs.re) <= minDiff) && (std::abs(im - rhs.im) <= minDiff);; }
  bool operator==(const double rhs) const { return (std::abs(re - rhs) <= minDiff) && (std::abs(im) <= minDiff);; }
  bool operator!=(const Complex rhs) const { return !operator==(rhs); }
  bool operator!=(const double rhs) const { return !operator==(rhs); }

  /// ASSIGNING OPERATIONS
  Complex& operator+=(const Complex rhs);
  Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }

  Complex& operator-=(const Complex rhs);
  Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }

  Complex& operator*=(const Complex rhs);
  Complex& operator*=(const double rhs) { return operator-=(Complex(rhs)); }

  Complex& operator/=(const Complex rhs);
  Complex& operator/=(const double rhs) { return operator-=(Complex(rhs)); }

  /// DESTRUCTOR
  ~Complex() = default;

  /// INPUT & OUTPUT DECLARATION
  std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
  std::istream& ReadFrom(std::istream& istrm) noexcept;

  double re{0.0};
  double im{0.0};

  static const char leftBrace{'{'};
  static const char separator{','};
  static const char rightBrace{'}'};
  const double minDiff = 2 * std::numeric_limits<double>::epsilon();
};

///DEFAULT OPERATORS
Complex operator+(const Complex lhs, const Complex rhs) noexcept;
Complex operator+(const double lhs, const Complex rhs) noexcept;
Complex operator+(const Complex lhs, const double rhs) noexcept;

Complex operator-(const Complex lhs, const Complex rhs) noexcept;
Complex operator-(const double lhs, const Complex rhs) noexcept;
Complex operator-(const Complex lhs, const double rhs) noexcept;

Complex operator*(const Complex lhs, const Complex rhs) noexcept;
Complex operator*(const double lhs, const Complex rhs) noexcept;
Complex operator*(const Complex lhs, const double rhs) noexcept;

Complex operator/(const Complex lhs, const Complex rhs);
Complex operator/(const double lhs, const Complex rhs);
Complex operator/(const Complex lhs, const double rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex rhs) noexcept
{
  return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept
{
  return rhs.ReadFrom(istrm);
}
#endif