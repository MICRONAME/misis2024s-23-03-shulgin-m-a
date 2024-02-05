//
// Created by user on 05.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_STACKARR_STACKARR_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_STACKARR_STACKARR_HPP_

#include <complex/complex.hpp>
#include <cstddef>

class Stackarr{
 public:
  Stackarr();
  Stackarr(const Stackarr& rhs);
  ~Stackarr();
  Stackarr& operator=(const Stackarr& rhs);

  void push(const Complex& rhs);
  void pop();
  bool empty();
  const Complex& top();

  [[nodiscard]] std::ptrdiff_t size() const { return size_; }
  [[nodiscard]] std::ptrdiff_t capacity() const { return capacity_; }

 private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 10;
  Complex* data_;
};

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_STACKARR_STACKARR_HPP_
