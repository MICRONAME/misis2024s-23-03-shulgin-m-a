#include <stackarr/stackarr.hpp>
#include <iostream>

int main(){
  Stackarr st(5);
  std::cout << st.top() << "\n";
  st.push(Complex(4));
  std::cout << st.top() << "\n";
  st.pop();
  std::cout << st.top() << "\n";
  std::cout << st.empty() << "\n";
  Stackarr b(st);
  b.push(Complex(5));
  std::cout << b.top() << "\n";
  b.pop();
  std::cout << b.top() << "\n";
  std::cout << b.empty() << "\n";
}