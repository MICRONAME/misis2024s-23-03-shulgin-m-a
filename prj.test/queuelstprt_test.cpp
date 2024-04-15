//
// Created by user on 08.04.2024.
//
#include <queuelstprT/queuelstprT.hpp>
#include <iostream>
#define nl "\n"

int main(){
  QueueLstPrT<int> a;
  a.Push(5);
  a.Push(4);
  std::cout << a.Top() << nl;
  a.Pop();
  std::cout << a.Top() << nl;
  std::cout << a.IsEmpty() << nl;
  a.Pop();
  std::cout << a.IsEmpty() << nl;
  //std::cout << a.Top() << nl;
}