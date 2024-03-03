#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklst/stacklst.hpp>

TEST_CASE("cons") {
  SUBCASE("default") {
    StackLst a;
    CHECK(a.Size() == 0);
  }
  SUBCASE("copy") {
    StackLst a;
    for (int i = 0; i < 500; ++i)
      a.Push(Complex());

    StackLst b(a);
    CHECK(b.Size() == 500);

    b.Push(Complex());
    CHECK(b.Size() == 501);
    CHECK(a.Size() == 500);
  }
}

TEST_CASE("appr") {
  SUBCASE("appr with empty") {
    StackLst a;
    StackLst b;
    for (int i = 0; i < 5; ++i)
      b.Push(Complex());
    a = b;
    CHECK(a.Size() == 5);

    b.Push(Complex());
    CHECK(b.Size() == 6);
    CHECK(a.Size() == 5);
  }
  SUBCASE("appr with full") {
    StackLst a;
    StackLst b;
    for (int i = 0; i < 5; ++i)
    {
      a.Push(Complex());
      b.Push(Complex());
    }
    a = b;
    CHECK(a.Size() == 5);

    b.Push(Complex());
    CHECK(b.Size() == 6);
    CHECK(a.Size() == 5);
  }
}

TEST_CASE("Push, Pop & Top"){
  StackLst a;
  CHECK(a.Size() == 0);
  for (int i = 0; i < 1000; ++i)
  {
    a.Push(Complex(i, i));
    CHECK(a.Size() == i + 1);
    CHECK(a.Top() == Complex(i, i));
  }

  for (int i = 998; i >= 0; --i)
  {
    a.Pop();
    CHECK(a.Size() == i + 1);
    CHECK(a.Top() == Complex(i, i));
  }
  a.Pop();
  CHECK_THROWS(a.Top());
  a.Pop();
}