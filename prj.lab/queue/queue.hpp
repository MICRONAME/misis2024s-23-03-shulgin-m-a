//
// Created by user on 19.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUE_QUEUE_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUE_QUEUE_HPP_

#include <complex/complex.hpp>

class Queue{
 public:
  Queue() = default;
  Queue(const Queue& rhs);
  ~Queue();

  Queue& operator=(const Queue& rhs);

  Complex top();
  bool empty();
  void push(const Complex& rhs);
  void pop();

 private:
  struct Node{
   Complex el;
   Node* pointer = nullptr;
 };
 Node* head = nullptr;
 Node* tail = nullptr;
};

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUE_QUEUE_HPP_
