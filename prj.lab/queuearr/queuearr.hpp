//
// Created by user on 26.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUEARR_QUEUEARR_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUEARR_QUEUEARR_HPP_

#include <complex/complex.hpp>
#include <cstddef>

class QueueArr{
 public:
  QueueArr();
  QueueArr(const QueueArr&);
  ~QueueArr();

  Complex Top();
  [[nodiscard]] const Complex Top() const;
  [[nodiscard]] bool IsEmpty() const noexcept;
  void Push(const Complex& rhs);
  void Pop() noexcept;

  QueueArr& operator=(const QueueArr& rhs);

 private:
  Complex* data_;
  std::ptrdiff_t head_;
  std::ptrdiff_t tail_;
  std::ptrdiff_t capacity_;
};

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUEARR_QUEUEARR_HPP_
