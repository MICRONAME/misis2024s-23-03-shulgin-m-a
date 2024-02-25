//
// Created by user on 12.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackLst_StackLst_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackLst_StackLst_HPP_

#include <complex/complex.hpp>
#include <cstddef>

class StackLst{
 public:
  ///DEFAULT CONSTRUCTOR
  StackLst() = default;

  ///COPY CONSTRUCTOR
  StackLst(const StackLst &rhs);

  ///DESTRUCTOR
  ~StackLst();

  ///OVERLOADING OPERATOR =
  [[nodiscard]] StackLst &operator=(const StackLst &rhs);

  ///PushES NEW ELEMENT TO THE Top
  void Push(const Complex &rhs);

  ///DELETING ELEMENT FROM THE Top
  void Pop() noexcept;

  void Clear() noexcept;

  ///CHECKING EMPTITY
  [[nodiscard]] bool IsEmpty() const noexcept;

  ///GETS Top VALUE
  [[nodiscard]] const Complex& Top() const;

  [[nodiscard]] Complex& Top();

/*
  ///GETS PRIVATE SIZE VALUE
  [[nodiscard]] std::ptrdiff_t size() const { return size_; }
  [[nodiscard]] std::ptrdiff_t capacity() const { return capacity_; }
*/
 private:
  struct Node{
    Complex el;
    Node* prev = nullptr;
  };
  Node* head = nullptr;
};


#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackLst_StackLst_HPP_
