//
// Created by user on 19.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QueueLst_QueueLst_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QueueLst_QueueLst_HPP_

#include <complex/complex.hpp>
#include <cstdint>

class QueueLst{
 public:
  QueueLst() = default;

  QueueLst(const QueueLst&);

  ~QueueLst();

  [[nodiscard]] QueueLst& operator=(const QueueLst&);

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;
  int64_t Size(){return size;};

 private:
  struct Node{
   Complex el;
   Node* pointer = nullptr;
 };
 Node* head = nullptr;
 Node* tail = nullptr;
 int64_t size = 0;
};

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QueueLst_QueueLst_HPP_
