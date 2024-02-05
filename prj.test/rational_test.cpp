#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <sstream>
#include "doctest.h"
#include <rational/rational.hpp>

TEST_CASE("test constructors") {
  Rational a;
  CHECK(0 == a.num());
  CHECK(1 == a.den());

  Rational b(3);
  CHECK(3 == b.num());
  CHECK(1 == b.den());

  Rational c(3, 2);
  CHECK(3 == c.num());
  CHECK(2 == c.den());

  Rational d(4, 2);
  CHECK(2 == d.num());
  CHECK(1 == d.den());

  CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("test appropriation") {
  Rational a(3, 2);
  Rational b(1, 2);
  CHECK((a = b) == Rational(1, 2));
}

TEST_CASE("test arifmetic")
{
  Rational a(1, 2);
  SUBCASE("appropriation arifmetic") {
    Rational b(5, 6);
    SUBCASE("sum") {
      a += b;
      CHECK(a == Rational(4, 3));
      CHECK(b == Rational(5, 6));
    }
    SUBCASE("diff") {
      a -= b;
      CHECK(a == Rational(-1, 3));
      CHECK(b == Rational(5, 6));
    }
    SUBCASE("mult") {
      a *= b;
      CHECK(a == Rational(5, 12));
      CHECK(b == Rational(5, 6));
    }
    SUBCASE("dev") {
      a /= b;
      CHECK(a == Rational(3, 5));
      CHECK(b == Rational(5, 6));

      Rational c(0);
      CHECK_THROWS(a /= c);
    }
  }

  SUBCASE("arifmetic Rational Rational") {
    Rational b(5, 6);
    SUBCASE("sum") {
      CHECK((a + b) == Rational(4, 3));
      CHECK(a == Rational(1, 2));
      CHECK(b == Rational(5, 6));
    }
    SUBCASE("diff") {
      CHECK((a - b) == Rational(-1, 3));
      CHECK(a == Rational(1, 2));
      CHECK(b == Rational(5, 6));
    }
    SUBCASE("mult") {
      CHECK((a * b) == Rational(5, 12));
      CHECK(a == Rational(1, 2));
      CHECK(b == Rational(5, 6));
    }
    SUBCASE("dev") {
      CHECK((a / b) == Rational(3, 5));
      CHECK(a == Rational(1, 2));
      CHECK(b == Rational(5, 6));

      Rational c(0);
      CHECK_THROWS(a / c);
    }
  }

  SUBCASE("arifmetic Rational int") {
    int b = 3;
    SUBCASE("sum") {
      CHECK((a + b) == Rational(7, 2));
      CHECK(a == Rational(1, 2));
      CHECK(b == 3);
    }
    SUBCASE("diff") {
      CHECK((a - b) == Rational(-5, 2));
      CHECK(a == Rational(1, 2));
      CHECK(b == 3);
    }
    SUBCASE("mult") {
      CHECK((a * b) == Rational(3, 2));
      CHECK(a == Rational(1, 2));
      CHECK(b == 3);
    }
    SUBCASE("dev") {
      CHECK((a / b) == Rational(1, 6));
      CHECK(a == Rational(1, 2));
      CHECK(b == 3);

      int c = 0;
      CHECK_THROWS(a / c);
    }
  }

  SUBCASE("arifmetic int Rational") {
    int b = 3;
    SUBCASE("sum") {
      CHECK((b + a) == Rational(7, 2));
      CHECK(a == Rational(1, 2));
      CHECK(b == 3);
    }
    SUBCASE("diff") {
      CHECK((b - a) == Rational(5, 2));
      CHECK(a == Rational(1, 2));
      CHECK(b == 3);
    }
    SUBCASE("mult") {
      CHECK((b * a) == Rational(3, 2));
      CHECK(a == Rational(1, 2));
      CHECK(b == 3);
    }
    SUBCASE("dev") {
      CHECK((b / a) == Rational(6, 1));
      CHECK(a == Rational(1, 2));
      CHECK(b == 3);

      Rational c(0);
      CHECK_THROWS(b / c);
    }
  }
}

TEST_CASE("test comparation") {
  SUBCASE("Rational Rational")
  {
    Rational a(1, 2);
    Rational b(1, 2);
    Rational c(3, 1);
    Rational d(6, 2);
    SUBCASE("less") {
      CHECK((a < b) == false);
      CHECK(a == Rational(1, 2));
      CHECK(b == Rational(1, 2));
      CHECK((a < c) == true);
      CHECK(a == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((a < d) == true);
      CHECK(a == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((b < a) == false);
      CHECK(b == Rational(1, 2));
      CHECK(a == Rational(1, 2));
      CHECK((b < c) == true);
      CHECK(b == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((b < d) == true);
      CHECK(b == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((c < a) == false);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((c < b) == false);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((c < d) == false);
      CHECK(c == Rational(3, 1));
      CHECK(d == Rational(6, 2));

      CHECK((d < a) == false);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((d < b) == false);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((d < c) == false);
      CHECK(d == Rational(6, 2));
      CHECK(c == Rational(3, 1));
    }
    SUBCASE("less or equal") {
      CHECK((a <= b) == true);
      CHECK(a == Rational(1, 2));
      CHECK(b == Rational(1, 2));
      CHECK((a <= c) == true);
      CHECK(a == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((a <= d) == true);
      CHECK(a == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((b <= a) == true);
      CHECK(b == Rational(1, 2));
      CHECK(a == Rational(1, 2));
      CHECK((b <= c) == true);
      CHECK(b == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((b <= d) == true);
      CHECK(b == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((c <= a) == false);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((c <= b) == false);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((c <= d) == true);
      CHECK(c == Rational(3, 1));
      CHECK(d == Rational(6, 2));

      CHECK((d <= a) == false);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((d <= b) == false);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((d <= c) == true);
      CHECK(d == Rational(6, 2));
      CHECK(c == Rational(3, 1));
    }
    SUBCASE("equal") {
      CHECK((a == b) == true);
      CHECK(a == Rational(1, 2));
      CHECK(b == Rational(1, 2));
      CHECK((a == c) == false);
      CHECK(a == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((a == d) == false);
      CHECK(a == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((b == a) == true);
      CHECK(b == Rational(1, 2));
      CHECK(a == Rational(1, 2));
      CHECK((b == c) == false);
      CHECK(b == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((b == d) == false);
      CHECK(b == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((c == a) == false);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((c == b) == false);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((c == d) == true);
      CHECK(c == Rational(3, 1));
      CHECK(d == Rational(6, 2));

      CHECK((d == a) == false);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((d == b) == false);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((d == c) == true);
      CHECK(d == Rational(6, 2));
      CHECK(c == Rational(3, 1));
    }
    SUBCASE("not equal") {
      CHECK((a != b) == false);
      CHECK(a == Rational(1, 2));
      CHECK(b == Rational(1, 2));
      CHECK((a != c) == true);
      CHECK(a == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((a != d) == true);
      CHECK(a == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((b != a) == false);
      CHECK(b == Rational(1, 2));
      CHECK(a == Rational(1, 2));
      CHECK((b != c) == true);
      CHECK(b == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((b != d) == true);
      CHECK(b == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((c != a) == true);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((c != b) == true);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((c != d) == false);
      CHECK(c == Rational(3, 1));
      CHECK(d == Rational(6, 2));

      CHECK((d != a) == true);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((d != b) == true);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((d != c) == false);
      CHECK(d == Rational(6, 2));
      CHECK(c == Rational(3, 1));
    }
    SUBCASE("greater or equal") {
      CHECK((a >= b) == true);
      CHECK(a == Rational(1, 2));
      CHECK(b == Rational(1, 2));
      CHECK((a >= c) == false);
      CHECK(a == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((a >= d) == false);
      CHECK(a == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((b >= a) == true);
      CHECK(b == Rational(1, 2));
      CHECK(a == Rational(1, 2));
      CHECK((b >= c) == false);
      CHECK(b == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((b >= d) == false);
      CHECK(b == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((c >= a) == true);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((c >= b) == true);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((c >= d) == true);
      CHECK(c == Rational(3, 1));
      CHECK(d == Rational(6, 2));

      CHECK((d >= a) == true);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((d >= b) == true);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((d >= c) == true);
      CHECK(d == Rational(6, 2));
      CHECK(c == Rational(3, 1));
    }
    SUBCASE("greater") {
      CHECK((a > b) == false);
      CHECK(a == Rational(1, 2));
      CHECK(b == Rational(1, 2));
      CHECK((a > c) == false);
      CHECK(a == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((a > d) == false);
      CHECK(a == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((b > a) == false);
      CHECK(b == Rational(1, 2));
      CHECK(a == Rational(1, 2));
      CHECK((b > c) == false);
      CHECK(b == Rational(1, 2));
      CHECK(c == Rational(3, 1));
      CHECK((b > d) == false);
      CHECK(b == Rational(1, 2));
      CHECK(d == Rational(6, 2));

      CHECK((c > a) == true);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((c > b) == true);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((c > d) == false);
      CHECK(c == Rational(3, 1));
      CHECK(d == Rational(6, 2));

      CHECK((d > a) == true);
      CHECK(c == Rational(3, 1));
      CHECK(a == Rational(1, 2));
      CHECK((d > b) == true);
      CHECK(c == Rational(3, 1));
      CHECK(b == Rational(1, 2));
      CHECK((d > c) == false);
      CHECK(d == Rational(6, 2));
      CHECK(c == Rational(3, 1));
    }
  }

  SUBCASE("Rational int") {
    Rational a(4, 2);
    int b = 2;
    Rational c(6, 1);
    int d = 6;
    SUBCASE("less") {
      CHECK((a < b) == false);
      CHECK(a == Rational(4, 2));
      CHECK(b == 2);
      CHECK((a < c) == true);
      CHECK(a == Rational(4, 2));
      CHECK(c == Rational(6, 1));
      CHECK((a < d) == true);
      CHECK(a == Rational(4, 2));
      CHECK(d == 6);

      CHECK((c < a) == false);
      CHECK(c == Rational(6, 1));
      CHECK(a == Rational(4, 2));
      CHECK((c < b) == false);
      CHECK(c == Rational(6, 1));
      CHECK(b == 2);
      CHECK((c < d) == false);
      CHECK(c == Rational(6, 1));
      CHECK(d == 6);
    }
    SUBCASE("less or equal") {
      CHECK((a <= b) == true);
      CHECK(a == Rational(4, 2));
      CHECK(b == 2);
      CHECK((a <= c) == true);
      CHECK(a == Rational(4, 2));
      CHECK(c == Rational(6, 1));
      CHECK((a <= d) == true);
      CHECK(a == Rational(4, 2));
      CHECK(d == 6);

      CHECK((c <= a) == false);
      CHECK(c == Rational(6, 1));
      CHECK(a == Rational(4, 2));
      CHECK((c <= b) == false);
      CHECK(c == Rational(6, 1));
      CHECK(b == 2);
      CHECK((c <= d) == true);
      CHECK(c == Rational(6, 1));
      CHECK(d == 6);
    }
    SUBCASE("equal") {
      CHECK((a == b) == true);
      CHECK(a == Rational(4, 2));
      CHECK(b == 2);
      CHECK((a == c) == false);
      CHECK(a == Rational(4, 2));
      CHECK(c == Rational(6, 1));
      CHECK((a == d) == false);
      CHECK(a == Rational(4, 2));
      CHECK(d == 6);

      CHECK((c == a) == false);
      CHECK(c == Rational(6, 1));
      CHECK(a == Rational(4, 2));
      CHECK((c == b) == false);
      CHECK(c == Rational(6, 1));
      CHECK(b == 2);
      CHECK((c == d) == true);
      CHECK(c == Rational(6, 1));
      CHECK(d == 6);
    }
    SUBCASE("not equal") {
      CHECK((a != b) == false);
      CHECK(a == Rational(4, 2));
      CHECK(b == 2);
      CHECK((a != c) == true);
      CHECK(a == Rational(4, 2));
      CHECK(c == Rational(6, 1));
      CHECK((a != d) == true);
      CHECK(a == Rational(4, 2));
      CHECK(d == 6);

      CHECK((c != a) == true);
      CHECK(c == Rational(6, 1));
      CHECK(a == Rational(4, 2));
      CHECK((c != b) == true);
      CHECK(c == Rational(6, 1));
      CHECK(b == 2);
      CHECK((c != d) == false);
      CHECK(c == Rational(6, 1));
      CHECK(d == 6);
    }
    SUBCASE("greater or equal") {
      CHECK((a >= b) == true);
      CHECK(a == Rational(4, 2));
      CHECK(b == 2);
      CHECK((a >= c) == false);
      CHECK(a == Rational(4, 2));
      CHECK(c == Rational(6, 1));
      CHECK((a >= d) == false);
      CHECK(a == Rational(4, 2));
      CHECK(d == 6);

      CHECK((c >= a) == true);
      CHECK(c == Rational(6, 1));
      CHECK(a == Rational(4, 2));
      CHECK((c >= b) == true);
      CHECK(c == Rational(6, 1));
      CHECK(b == 2);
      CHECK((c >= d) == true);
      CHECK(c == Rational(6, 1));
      CHECK(d == 6);
    }
    SUBCASE("greater") {
      CHECK((a > b) == false);
      CHECK(a == Rational(4, 2));
      CHECK(b == 2);
      CHECK((a > c) == false);
      CHECK(a == Rational(4, 2));
      CHECK(c == Rational(6, 1));
      CHECK((a > d) == false);
      CHECK(a == Rational(4, 2));
      CHECK(d == 6);

      CHECK((c > a) == true);
      CHECK(c == Rational(6, 1));
      CHECK(a == Rational(4, 2));
      CHECK((c > b) == true);
      CHECK(c == Rational(6, 1));
      CHECK(b == 2);
      CHECK((c > d) == false);
      CHECK(c == Rational(6, 1));
      CHECK(d == 6);
    }
  }

  SUBCASE("int Rational") {
    int a = 2;
    Rational b(4, 2);
    int c = 6;
    Rational d(6, 1);
    SUBCASE("less") {
      CHECK((a < b) == false);
      CHECK(a == 2);
      CHECK(b == Rational(4, 2));
      CHECK((a < d) == true);
      CHECK(a == 2);
      CHECK(d == Rational(6, 1));

      CHECK((c < b) == false);
      CHECK(c == 6);
      CHECK(b == Rational(4, 2));
      CHECK((c < d) == false);
      CHECK(d == Rational(6, 1));
      CHECK(c == 6);
    }
    SUBCASE("less or equal") {
      CHECK((a <= b) == true);
      CHECK(a == 2);
      CHECK(b == Rational(4, 2));
      CHECK((a <= d) == true);
      CHECK(a == 2);
      CHECK(d == Rational(6, 1));

      CHECK((c <= b) == false);
      CHECK(c == 6);
      CHECK(b == Rational(4, 2));
      CHECK((c <= d) == true);
      CHECK(d == Rational(6, 1));
      CHECK(c == 6);
    }
    SUBCASE("equal") {
      CHECK((a == b) == true);
      CHECK(a == 2);
      CHECK(b == Rational(4, 2));
      CHECK((a == d) == false);
      CHECK(a == 2);
      CHECK(d == Rational(6, 1));

      CHECK((c == b) == false);
      CHECK(c == 6);
      CHECK(b == Rational(4, 2));
      CHECK((c == d) == true);
      CHECK(d == Rational(6, 1));
      CHECK(c == 6);
    }
    SUBCASE("not equal") {
      CHECK((a != b) == false);
      CHECK(a == 2);
      CHECK(b == Rational(4, 2));
      CHECK((a != d) == true);
      CHECK(a == 2);
      CHECK(d == Rational(6, 1));

      CHECK((c != b) == true);
      CHECK(c == 6);
      CHECK(b == Rational(4, 2));
      CHECK((c != d) == false);
      CHECK(d == Rational(6, 1));
      CHECK(c == 6);
    }
    SUBCASE("greater or equal") {
      CHECK((a >= b) == true);
      CHECK(a == 2);
      CHECK(b == Rational(4, 2));
      CHECK((a >= d) == false);
      CHECK(a == 2);
      CHECK(d == Rational(6, 1));

      CHECK((c >= b) == true);
      CHECK(c == 6);
      CHECK(b == Rational(4, 2));
      CHECK((c >= d) == true);
      CHECK(d == Rational(6, 1));
      CHECK(c == 6);
    }
    SUBCASE("greater") {
      CHECK((a > b) == false);
      CHECK(a == 2);
      CHECK(b == Rational(4, 2));
      CHECK((a > d) == false);
      CHECK(a == 2);
      CHECK(d == Rational(6, 1));

      CHECK((c > b) == true);
      CHECK(c == 6);
      CHECK(b == Rational(4, 2));
      CHECK((c > d) == false);
      CHECK(d == Rational(6, 1));
      CHECK(c == 6);
    }
  }
}

TEST_CASE("test io") {
  SUBCASE("input") {
    SUBCASE("1/2") {
      std::istringstream ss("1/2");
      Rational a;
      ss >> a;
      CHECK(a == Rational(1, 2));
    }
    SUBCASE("1/0") {
      std::istringstream ss("1/0 ");
      Rational a;
      ss >> a;
      CHECK(a == Rational(0, 1));
      CHECK(ss.good() == false);
    }
    SUBCASE("10") {
      std::istringstream ss("10 ");
      Rational a;
      ss >> a;
      CHECK(a == Rational(0, 1));
      CHECK(ss.good() == false);
    }
    SUBCASE("0/5") {
      std::istringstream ss("0/5 ");
      Rational a;
      ss >> a;
      CHECK(a == Rational(0, 1));
    }
    SUBCASE("2/6") {
      std::istringstream ss("2/6 ");
      Rational a;
      ss >> a;
      CHECK(a == Rational(1, 3));
    }
    SUBCASE("2 /6") {
      std::istringstream ss("2 /6 ");
      Rational a;
      ss >> a;
      CHECK(a == Rational(0, 1));
      CHECK(ss.good() == false);
    }
    SUBCASE("2/ 6") {
      std::istringstream ss("2/ 6 ");
      Rational a;
      ss >> a;
      CHECK(a == Rational(0, 1));
      CHECK(ss.good() == false);
    }
    SUBCASE("2 / 6") {
      std::istringstream ss("2 / 6 ");
      Rational a;
      ss >> a;
      CHECK(a == Rational(0, 1));
      CHECK(ss.good() == false);
    }
  }
  SUBCASE("output") {
    SUBCASE("Rational()") {
      std::stringstream ss;
      Rational a;
      ss << a;
      CHECK(ss.str() == "0/1");
    }
    SUBCASE("Rational(3)") {
      std::stringstream ss;
      Rational a(3);
      ss << a;
      CHECK(ss.str() == "3/1");
    }
    SUBCASE("Rational(3, 2)") {
      std::stringstream ss;
      Rational a(3, 2);
      ss << a;
      CHECK(ss.str() == "3/2");
    }
    SUBCASE("Rational(4, 2)") {
      std::stringstream ss;
      Rational a(4, 2);
      ss << a;
      CHECK(ss.str() == "2/1");
    }
  }
}