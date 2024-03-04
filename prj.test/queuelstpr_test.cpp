//
// Created by user on 04.03.2024.
//

#include <queuelstpr/queuelstpr.hpp>
#include <iostream>

int main(){
  QueueLstPr a;
  a.Push(5);
  std::cout << a.Top() << "\n";
  a.Push(3);
  std::cout << a.Top() << "\n";
  a.Push(7);
  std::cout << a.Top() << "\n";
  a.Push(9);
  std::cout << a.Top() << "\n";
  a.Push(5);
  std::cout << a.Top() << "\n";
  a.Push(7);
  std::cout << a.Top() << "\n";
  a.Pop();
  std::cout << a.Top() << "\n";
  a.Pop();
  std::cout << a.Top() << "\n";
  a.Pop();
  std::cout << a.Top() << "\n";
  a.Pop();
  std::cout << a.Top() << "\n";
  a.Pop();
  std::cout << a.Top() << "\n";
}
