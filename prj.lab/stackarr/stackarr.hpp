//
// Created by user on 05.02.2024.
//
#pragma once
#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackArr_StackArr_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackArr_StackArr_HPP_

#include <complex/complex.hpp>
#include <cstddef>

class StackArr {
 public:
  ///DEFAULT CONSTRUCTOR
  StackArr();
  ///COPY CONSTRUCTOR
  StackArr(const StackArr &rhs);
  ///CONSTRUCTOR BY SIZE
  //explicit StackArr(std::ptrdiff_t size);
  ///DESTRUCTOR
  ~StackArr();
  ///OVERLOADING OPERATOR =
  StackArr &operator=(const StackArr &rhs);

  ///PUSHES NEW ELEMENT TO THE TOP
  void Push(const Complex &rhs);
  ///DELETING ELEMENT FROM THE TOP
  void Pop() noexcept;
  ///CHECKING EMPTITY
  [[nodiscard]] bool IsEmpty() const noexcept;
  ///GETS TOP VALUE
  [[nodiscard]] const Complex& Top() const;

  [[nodiscard]] std::ptrdiff_t Size() const{ return size_; };

  Complex& Top();

  void Clear() noexcept;

 private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 0;
  Complex* data_ = nullptr;
};

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackArr_StackArr_HPP_
