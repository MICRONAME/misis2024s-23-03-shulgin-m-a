//
// Created by user on 26.02.2024.
//
#include <queuearr/queuearr.hpp>
#include <iostream>

int main(){
  //не работает, надо чинить
  QueueArr a;
  a.Push(Complex(5));
  std::cout << a.Top() << "\n";
  a.Push(Complex(6));
  std::cout << a.Top() << "\n";
  a.Pop();
  std::cout << a.Top() << "\n";
}