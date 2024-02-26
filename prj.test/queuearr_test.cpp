//
// Created by user on 26.02.2024.
//
#include <queuearr/queuearr.hpp>
#include <iostream>

int main(){
  QueueArr a;
  a.Push(Complex(5));
  std::cout << a.Top() << "\n";
}