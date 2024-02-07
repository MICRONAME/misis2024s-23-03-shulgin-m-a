//
// Created by user on 05.02.2024.
//
#include <stackarr/stackarr.hpp>
#include <stdexcept>

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
  size_++;
  if (capacity_ == size_){
    data_ = new Complex [capacity_];
    capacity_ = 2 * size_;
  }
  data_[size_] = rhs;
}

void Stackarr::pop() {
  if (size_ == 0) throw std::runtime_error("cannot pop value: stack is empty");
  data_[size_] = 0;
  size_--;
}

bool Stackarr::empty() const {
  if (size_ == 0) return true;
  return false;
}

Complex Stackarr::top() const {
  if (size_ == 0) throw std::runtime_error("cannot get top value: stack is empty");
  return data_[size_];
}
Stackarr::Stackarr(const std::ptrdiff_t size) {
  if (size <= 0) throw std::runtime_error("size <= 0");
  else {
    if (2 * size > capacity_) capacity_ = 2 * size;
    size_ = size;
    data_ = new Complex[capacity_];
    for (std::ptrdiff_t i = 0; i < size_; ++i) data_[i] = 0;
  }
}
