//
// Created by user on 17.02.2024.
//

#include <stacklst/stacklst.hpp>
#include <iostream>
int main(){
  Stacklst a;
  a.push(Complex(5));
  a.push(Complex(6));
  std::cout << a.top() << "\n";
  Stacklst b(a);
  std::cout << b.top() << ' ' << a.top() << "\n";
  b.pop();
  std::cout << b.top() << ' ' << a.top();
}