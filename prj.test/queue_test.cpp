//
// Created by user on 19.02.2024.
//

#include <queue/queue.hpp>
#include <iostream>

int main(){
  Queue a;
  //std::cout << a.top() << "\n";
  a.push(Complex(5));
  std::cout << a.top() << "\n";
  a.push(Complex(6));
  std::cout << a.top() << "\n";
  a.pop();
  std::cout << a.top() << "\n";
}