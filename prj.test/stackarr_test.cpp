#include <stackarr/stackarr.hpp>
#include <iostream>

int main(){
  Stackarr a;
  Stackarr b;
  a.push({5,0});
  b.push({6,0});
  std::cout << a.size() << ' ' << b.size() << "\n";
  std::cout << a.capacity() << ' ' << b.capacity() << "\n";
  std::cout << a.top() << ' ' << b.top() << "\n";
  a = b;
  a.pop();
  b.pop();
  std::cout << "aboba" << "\n";
  std::cout << a.size() << ' ' << b.size() << "\n";
  std::cout << a.capacity() << ' ' << b.capacity() << "\n";
  std::cout << a.top() << ' ' << b.top() << "\n";
}