//
// Created by user on 12.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_STACKLST_STACKLST_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_STACKLST_STACKLST_HPP_

#include <complex/complex.hpp>
#include <cstddef>

class Stacklst{
 public:
  ///DEFAULT CONSTRUCTOR
  Stacklst() = default;

  ///COPY CONSTRUCTOR
  Stacklst(const Stacklst &rhs);

  ///DESTRUCTOR
  ~Stacklst();

  ///OVERLOADING OPERATOR =
  Stacklst &operator=(const Stacklst &rhs);

  ///PUSHES NEW ELEMENT TO THE TOP
  void push(const Complex &rhs);

  ///DELETING ELEMENT FROM THE TOP
  void pop();

  void clear() noexcept;

  ///CHECKING EMPTITY
  [[nodiscard]] bool empty() const noexcept;

  ///GETS TOP VALUE
  [[nodiscard]] Complex top() const;

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


#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_STACKLST_STACKLST_HPP_
