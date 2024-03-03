#include <iostream>
#include <stdexcept>
#include <complex/complex.hpp>

Complex& Complex::operator= (const Complex rhs) {
  re = rhs.re;
  im = rhs.im;
  return *this;
}
Complex& Complex::operator= (const double rhs) {
  re = rhs;
  im = 0;
  return *this;
}
Complex& Complex::operator+= (const Complex rhs) {
  re += rhs.re;
  im += rhs.im;
  return *this;
}
Complex& Complex::operator+= (const double rhs) {
  re += rhs;
  return *this;
}
Complex& Complex::operator-= (const Complex rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}
Complex& Complex::operator-= (const double rhs) {
  re -= rhs;
  return *this;
}
Complex& Complex::operator*= (const Complex rhs) {
  double a = re * rhs.re - im * rhs.im;
  double b = im * rhs.re + re * rhs.im;
  re = a;
  im = b;
  return *this;
}
Complex& Complex::operator*= (const double rhs) {
  *this *= Complex(rhs);
  return *this;
}
Complex& Complex::operator/= (const Complex rhs) {
  if (rhs == 0.0) {
    throw std::runtime_error("Complex devision by zero");
  }
  double a = (re * rhs.re + im * rhs.im) /
      (rhs.re * rhs.re + rhs.im * rhs.im);
  double b = (im * rhs.re - re * rhs.im) /
      (rhs.re * rhs.re + rhs.im * rhs.im);
  re = a;
  im = b;
  return *this;
}
Complex& Complex::operator/= (const double rhs) {
  *this /= Complex(rhs);
  return *this;
}

Complex operator+ (const Complex lhs, const Complex rhs) {
  Complex answer(lhs);
  answer += rhs;
  return answer;
}
Complex operator+ (const Complex lhs, const double rhs) {
  Complex answer(lhs);
  answer += rhs;
  return answer;
}
Complex operator+ (const double lhs, const Complex rhs) {
  Complex answer(lhs);
  answer += rhs;
  return answer;
}
Complex operator- (const Complex lhs, const Complex rhs) {
  Complex answer(lhs);
  answer -= rhs;
  return answer;
}
Complex operator- (const Complex lhs, const double rhs) {
  Complex answer(lhs);
  answer -= rhs;
  return answer;
}
Complex operator- (const double lhs, const Complex rhs) {
  Complex answer(lhs);
  answer -= rhs;
  return answer;
}
Complex operator* (const Complex lhs, const Complex rhs) {
  Complex answer(lhs);
  answer *= rhs;
  return answer;
}
Complex operator* (const Complex lhs, const double rhs) {
  Complex answer(lhs);
  answer *= rhs;
  return answer;
}
Complex operator* (const double lhs, const Complex rhs) {
  Complex answer(lhs);
  answer *= rhs;
  return answer;
}
Complex operator/ (const Complex lhs, const Complex rhs) {
  Complex answer(lhs);
  answer /= rhs;
  return answer;
}
Complex operator/ (const Complex lhs, const double rhs) {
  Complex answer(lhs);
  answer /= rhs;
  return answer;
}
Complex operator/ (const double lhs, const Complex rhs) {
  Complex answer(lhs);
  answer /= rhs;
  return answer;
}

bool Complex::operator== (const Complex rhs) const {
  return (abs(re - rhs.re) <= minDiff) && (abs(im - rhs.im) <= minDiff);
}
bool Complex::operator== (const double rhs) const {
  return (abs(re - rhs) < minDiff) && (abs(im) < minDiff);
}
bool Complex::operator!= (const Complex rhs) const {
  return !(*this == rhs);
}
bool Complex::operator!= (const double rhs) const {
  return !(*this == rhs);
}

void Complex::conjugate() {
  im *= -1;
}

std::ostream& Complex::WriteTo(std::ostream& stream) const {
  stream << Complex::leftBrace << re << Complex::separator << im << Complex::rightBrace;
  return stream;
}
std::istream& Complex::ReadFrom(std::istream& stream) {
  char leftBrace{ 0 };
  double real{ 0 };
  char separator{ 0 };
  double imaginary{ 0 };
  char rightBrace{ 0 };
  stream >> leftBrace >> real >> separator >> imaginary >> rightBrace;

  if (stream.good()) {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator == separator)
        && (Complex::rightBrace == rightBrace)) {
      re = real;
      im = imaginary;
    }
    else {
      stream.setstate(std::ios_base::failbit);
    }
  }

  return stream;
}

std::istream& operator>> (std::istream& stream, Complex& val) {
  return val.ReadFrom(stream);
}
std::ostream& operator<< (std::ostream& stream, const Complex val) {
  return val.WriteTo(stream);
}
