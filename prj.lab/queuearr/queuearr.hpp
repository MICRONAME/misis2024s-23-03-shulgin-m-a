//
// Created by user on 26.02.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUEARR_QUEUEARR_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUEARR_QUEUEARR_HPP_

#include <complex/complex.hpp>
#include <cstddef>
#include <cstdint>

class QueueArr{
 public:
  QueueArr();
  QueueArr(const QueueArr& rhs);
  QueueArr(QueueArr &&) noexcept ;
  ~QueueArr();

  Complex& Top();
  [[nodiscard]] const Complex& Top() const;
  [[nodiscard]] bool IsEmpty() const noexcept;
  void Push(const Complex& rhs);
  void Pop() noexcept;
  void Clear() noexcept;

  QueueArr& operator=(const QueueArr& rhs);
  QueueArr& operator=(QueueArr &&) noexcept;

  int Size() const {
    if ((head_ + 1) % capacity_ <= tail_)
      return tail_ - head_ - 1;
    else
      return capacity_ - head_ - 1 + tail_;
  }

 private:
  Complex* data_ = nullptr;
  std::ptrdiff_t head_ = -1;
  std::ptrdiff_t tail_ = 0;
  std::ptrdiff_t capacity_ = 10;
};

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUEARR_QUEUEARR_HPP_
