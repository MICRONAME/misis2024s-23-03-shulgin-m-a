//
// Created by user on 22.04.2024.
//
#include <chrono>
#include <queuelstprT/queuelstprT.hpp>
#include <iostream>

using seconds = std::chrono::duration<long long>;
using milliseconds = std::chrono::duration<long long, std::milli>;
using microseconds  = std::chrono::duration<long long, std::micro>;
using nanoseconds  = std::chrono::duration<long long, std::nano>;

int main(){

  //todo: IMPORTANT to use steady_clock::now() only in if clause, because otherwise time spends on initializing variables etc, so function time is incorrect
  //todo: also in debug mode time spends more than in default running: next if clause gives "1" in default run and nothing in debug mode

  auto start = std::chrono::steady_clock::now();
  QueueLstPrT<int> a;
  if (std::chrono::steady_clock::now() - start < milliseconds {1})
    std::cout << true << "\n";

  start = std::chrono::steady_clock::now();
  a.Push(5);
  if (std::chrono::steady_clock::now() - start < milliseconds {1})
    std::cout << true << "\n";

  start = std::chrono::steady_clock::now();
  a.Pop();
  if (std::chrono::steady_clock::now() - start < milliseconds {1})
    std::cout << true << "\n";

  a.Push(5);

  start = std::chrono::steady_clock::now();
  int t = 5;
  auto varTime = std::chrono::steady_clock::now() - start;

  start = std::chrono::steady_clock::now();
  auto top = a.Top();
  if (std::chrono::steady_clock::now() - start - varTime < milliseconds {1})
    std::cout << true << "\n";

  for (int i = 0; i < 100; i++){
    start = std::chrono::steady_clock::now();
    a.Push(100 - i);
    if (std::chrono::steady_clock::now() - start < microseconds {1})
      std::cout << i << ' ' << "Correct push in time" << "\n";
  }
}