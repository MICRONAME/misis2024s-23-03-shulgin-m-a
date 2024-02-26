//
// Created by user on 12.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackLst_StackLst_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackLst_StackLst_HPP_

#include <complex/complex.hpp>
#include <cstddef>

class StackLst{
 public:
  StackLst() = default;

  StackLst(const StackLst&);

  ~StackLst();

  [[nodiscard]] StackLst& operator=(const StackLst&);

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

 private:
  struct Node{
    Complex el;
    Node* prev = nullptr;
  };
  Node* head = nullptr;
};


#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackLst_StackLst_HPP_
