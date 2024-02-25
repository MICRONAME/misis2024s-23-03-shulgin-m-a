//
// Created by user on 19.02.2024.
//

#include <queue/queue.hpp>
#include <iostream>

int main(){
  Queue c;
  for (int i = 0; i < 100; i++) {
    c.push(Complex(i));
    std::cout << c.top() << "\n";
  }
  Queue d;
  for (int i = 101; i < 105; i++) {
    d.push(Complex(i));
    std::cout << c.top() << "\n";
  }
  c = d;
  std::cout << c.top() << "\n";
}