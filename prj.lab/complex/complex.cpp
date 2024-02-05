#include <iostream>
#include <sstream>
#include <complex/complex.hpp>

///DEFINITION OF DEFAULT OPERATORS

Complex operator+(const Complex lhs, const Complex rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const Complex lhs, const double rhs) noexcept { return Complex(lhs) += Complex(rhs); }
Complex operator+(const double lhs, const Complex rhs) noexcept { return Complex(lhs) += rhs; }

Complex operator-(const Complex lhs, const Complex rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const Complex lhs, const double rhs) noexcept { return Complex(lhs) -= Complex(rhs); }
Complex operator-(const double lhs, const Complex rhs) noexcept { return Complex(lhs) -= rhs; }

Complex operator*(const Complex lhs, const Complex rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const Complex lhs, const double rhs) noexcept { return Complex(lhs) *= Complex(rhs); }
Complex operator*(const double lhs, const Complex rhs) noexcept { return Complex(lhs) *= rhs; }

Complex operator/(const Complex lhs, const Complex rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const Complex lhs, const double rhs) { return Complex(lhs) /= Complex(rhs); }
Complex operator/(const double lhs, const Complex rhs) { return Complex(lhs) /= rhs; }

///DEFINITION OF ASSIGNING OPERATORS

Complex& Complex::operator+=(const Complex rhs)
{
  re += rhs.re;
  im += rhs.im;
  return *this;
}

Complex& Complex::operator*=(const Complex rhs)
{
  double a, b;
  a = re * rhs.re;
  a -= im * rhs.im;
  b = im * rhs.re;
  b += re * rhs.im;
  re = a;
  im = b;
  return *this;
}



Complex& Complex::operator-=(const Complex rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}

Complex& Complex::operator/=(const Complex rhs) {
  if (rhs.re == 0 && rhs.im == 0){
    throw std::runtime_error("Div by zero");
  }
  else {
    auto real = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    auto imagin = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    re = real;
    im = imagin;
  }
  return *this;
}

///INPUT OUTPUT

std::ostream &Complex::WriteTo(std::ostream &ostrm) const noexcept
{
  ostrm << leftBrace << re << separator << im << rightBrace;
  return ostrm;
}

std::istream &Complex::ReadFrom(std::istream &istrm) noexcept
{
  char left(0);
  double rea(0.0);
  char comma(0);
  double ima(0.0);
  char right(0);
  istrm >> left >> rea >> comma >> ima >> right;
  if (istrm.good())
  {
    if ((Complex::leftBrace == left) && (Complex::separator == comma) && (Complex::rightBrace == right))
    {
      re = rea;
      im = ima;
    }
    else
    {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}
/*
///INPUT TEST
bool Complex::testParse(const std::string &str)
{
  using namespace std;
  istringstream istrm(str);
  Complex z;
  istrm >> z;
  if (istrm.good())
  {
    cout << "Read success: " << str << " -> " << z << endl;
  }
  else
  {
    cout << "Read error : " << str << " -> " << z << endl;
    //cin >> z;
    //testParse('{' + to_string(z.re) + ',' + to_string(z.im) + '}');
  }
  return istrm.good();
}*/

///UNARY MINUS
Complex Complex::operator-() const noexcept {
  return Complex(-re, -im);
}

///CONJUGATED VALUE
void Complex::conjugate() {
  im *= -1;
}

///ASSIGNING
Complex& Complex::operator=(const Complex rhs) {
  re = rhs.re;
  im = rhs.im;
  return *this;
}

Complex& Complex::operator=(const double rhs) {
  return operator=(Complex(rhs));
}

