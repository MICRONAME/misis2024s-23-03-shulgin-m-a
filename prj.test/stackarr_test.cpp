#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <Stackarr/Stackarr.hpp>
#include "doctest.h"
#include <iostream>

TEST_CASE("cons") {
SUBCASE("default") {
Stackarr a;
CHECK(a.size() == 0);
}
SUBCASE("copy") {
Stackarr a;
for (int i = 0; i < 5; ++i)
a.push(Complex());

Stackarr b(a);
CHECK(b.size() == 5);

b.push(Complex());
CHECK(b.size() == 6);
CHECK(a.size() == 5);
}
}

TEST_CASE("appr") {
SUBCASE("appr with empty") {
Stackarr a;
Stackarr b;
for (int i = 0; i < 5; ++i)
b.push(Complex());
a = b;
CHECK(a.size() == 5);

b.push(Complex());
CHECK(b.size() == 6);
CHECK(a.size() == 5);
}
SUBCASE("appr with full") {
Stackarr a;
Stackarr b;
for (int i = 0; i < 5; ++i)
{
a.push(Complex());
b.push(Complex());
}
a = b;
CHECK(a.size() == 5);

b.push(Complex());
CHECK(b.size() == 6);
CHECK(a.size() == 5);
}
}

TEST_CASE("push, pop & top"){
  Stackarr a;
  CHECK(a.size() == 0);
  for (int i = 0; i < 10; ++i)
  {
    a.push(Complex(i, i));
    CHECK(a.size() == i + 1);
    CHECK(a.top() == Complex(i, i));
  }

  for (int i = 8; i >= 0; i--)
  {
    a.pop();
    CHECK(a.size() == i + 1);
    CHECK(a.top() == Complex(i, i));
  }
    a.pop();
    CHECK_THROWS(a.top());
    a.pop();
}