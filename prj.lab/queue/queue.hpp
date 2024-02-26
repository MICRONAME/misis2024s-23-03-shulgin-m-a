//
// Created by user on 19.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QueueLst_QueueLst_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QueueLst_QueueLst_HPP_

#include <complex/complex.hpp>

class QueueLst{
 public:
  QueueLst() = default;
  QueueLst(const QueueLst& rhs);
  ~QueueLst();

  QueueLst& operator=(const QueueLst& rhs);

  Complex Top();
  [[nodiscard]] const Complex Top() const;
  bool IsEmpty() const;
  void Push(const Complex& rhs);
  void Pop();
  void Clear();

 private:
  struct Node{
   Complex el;
   Node* pointer = nullptr;
 };
 Node* head = nullptr;
 Node* tail = nullptr;
};

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QueueLst_QueueLst_HPP_
