//
// Created by user on 05.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_STACKARR_STACKARR_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_STACKARR_STACKARR_HPP_

#include <complex/complex.hpp>
#include <cstddef>

class Stackarr {
 public:
  ///DEFAULT CONSTRUCTOR
  Stackarr();
  ///COPY CONSTRUCTOR
  Stackarr(const Stackarr &rhs);
  ///CONSTRUCTOR BY SIZE
  //explicit Stackarr(std::ptrdiff_t size);
  ///DESTRUCTOR
  ~Stackarr();
  ///OVERLOADING OPERATOR =
  Stackarr &operator=(const Stackarr &rhs);

  ///PUSHES NEW ELEMENT TO THE TOP
  void push(const Complex &rhs);
  ///DELETING ELEMENT FROM THE TOP
  void pop();
  ///CHECKING EMPTITY
  [[nodiscard]] bool empty() const noexcept;
  ///GETS TOP VALUE
  [[nodiscard]] const Complex top() const;

  ///GETS PRIVATE SIZE VALUE
  [[nodiscard]] std::ptrdiff_t size() const { return size_; }

  [[nodiscard]] std::ptrdiff_t capacity() const { return capacity_; }

  void clear() noexcept;

 private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 0;
  Complex* data_ = nullptr;
};

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_STACKARR_STACKARR_HPP_
