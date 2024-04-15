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
  StackArr() = default;
  StackArr(const StackArr &rhs);
  StackArr(StackArr &&) noexcept ;
  ~StackArr();
  StackArr &operator=(const StackArr &rhs);
  StackArr& operator=(StackArr &&) noexcept;

  void Push(const Complex &rhs);

  void Pop() noexcept;

  [[nodiscard]] bool IsEmpty() const noexcept;

  [[nodiscard]] const Complex& Top() const;

  [[nodiscard]] std::ptrdiff_t Size() const{ return size_ + 1; };

  Complex& Top();

  void Clear() noexcept;

 private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = -1;
  Complex* data_ = nullptr;
};

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_StackArr_StackArr_HPP_
