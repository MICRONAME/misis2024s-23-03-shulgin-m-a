//
// Created by user on 12.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackLst_StackLst_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackLst_StackLst_HPP_

#include <complex/complex.hpp>
#include <cstdint>

class StackLst{
 public:
  StackLst() = default;

  StackLst(const StackLst&);

  StackLst(StackLst &&) noexcept;

  ~StackLst();

  [[nodiscard]] StackLst& operator=(const StackLst&);
  StackLst& operator=(StackLst&&) noexcept;

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

  [[nodiscard]] int64_t Size() const noexcept { return size_; }

 private:
  struct Node{
    Complex el;
    Node* prev = nullptr;
  };
  Node* head = nullptr;
  int64_t size_ = 0;
};


#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackLst_StackLst_HPP_
