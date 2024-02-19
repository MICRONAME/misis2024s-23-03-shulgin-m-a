//
// Created by Егор Федюнин on 12.02.2024.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


#include <Stackarr/Stackarr.hpp>

TEST_CASE("Testing StackArr class") {
  SUBCASE("Testing methods"){
    Stackarr arr;
    Complex val = {1,0};
    Complex val1 = {3,4};
    arr.push(val);
    CHECK(arr.top() == val);
    arr.push(val1);
    CHECK(arr.top() == val1);
    arr.pop();
    CHECK(arr.top() == val);
    arr.pop();
    CHECK(arr.empty());
    arr.push(val);
    arr.push(val1);
    Stackarr arr1{arr};
    CHECK(arr1.top() == val1);
    arr.pop();
    CHECK(arr.top() == val);
    CHECK(arr1.top() == val1);
    arr.clear();
    arr.push(val);
    arr.push(val1);
    Stackarr arr2 = arr;
    CHECK(arr2.top() == val1);
    arr.pop();
    CHECK(arr2.top() == val1);
    CHECK(arr.top() == val);
  }
}