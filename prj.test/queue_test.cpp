//
// Created by user on 19.02.2024.
//

#include <queue/queue.hpp>
#include <iostream>

int main(){
  QueueLst c;
  for (int i = 0; i < 100; i++) {
    c.Push(Complex(i));
    //std::cout << c.Top() << "\n";
  }
  QueueLst d;
  for (int i = 101; i < 105; i++) {
    d.Push(Complex(i));
    //std::cout << c.Top() << "\n";
  }
  c = d;
  std::cout << c.Top() << "\n";
  c.Pop();
  std::cout << c.Top() << "\n";
  c.Pop();
  std::cout << c.Top() << "\n";
  c.Pop();
  std::cout << c.Top() << "\n";
  c.Push(Complex(1));
  std::cout << c.Top() << "\n";
  c.Pop();
  std::cout << c.Top() << "\n";
  c.Push(Complex(2));
  std::cout << c.Top() << "\n";
  c.Pop();
  std::cout << c.Top() << "\n";
}