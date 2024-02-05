//
// Created by user on 05.02.2024.
//
#include "stackarr.hpp"

Stackarr::Stackarr() {
  size_ = 0;
  capacity_ = 10;
  data_ = new Complex[10];
}
Stackarr::Stackarr(const Stackarr &rhs) {
  capacity_ = (capacity_ > 2 * rhs.size_ ? capacity_ : 2 * rhs.size_);
  size_ = rhs.size_;
  data_ = new Complex [capacity_];
  for (std::ptrdiff_t i = 0; i < size_; ++i)
    data_[i] = rhs.data_[i];

}
Stackarr::~Stackarr() {
  delete[] data_;
}

Stackarr &Stackarr::operator=(const Stackarr &rhs) {
  if (rhs.size_ > capacity_ || 4 * rhs.size_ < capacity_) {
    capacity_ = 2 * rhs.size_;
    size_ = rhs.size_;
    delete[] data_;
    data_ = new Complex[capacity_];
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      data_[i] = rhs.data_[i];
    }
    return *this;
  } else {
    size_ = rhs.size_;
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      data_[i] = rhs.data_[i];
    }
    return *this;
  }
}

void Stackarr::push(const Complex &rhs) {

}
void Stackarr::pop() {

}
bool Stackarr::empty() {
  if (size_ == 0) return 1;
  return 0;
}
const Complex &Stackarr::top() {
  return <#initializer#>;
}

