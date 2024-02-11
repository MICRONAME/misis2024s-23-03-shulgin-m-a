//
// Created by user on 05.02.2024.
//
#include <stackarr/stackarr.hpp>
#include <stdexcept>

Stackarr::Stackarr() {
  size_ = 0;
  capacity_ = 2;
  data_ = new Complex[capacity_];
}
Stackarr::Stackarr(const Stackarr &rhs) {
  size_ = rhs.size_;
  capacity_ = rhs.capacity_;
  data_ = new Complex [capacity_];
  for (std::ptrdiff_t i = 0; i < size_; ++i)
    data_[i] = rhs.data_[i];
}

Stackarr::~Stackarr() {
  delete[] data_;
}

Stackarr &Stackarr::operator=(const Stackarr &rhs) {
  size_ = rhs.size_;
  capacity_ = rhs.capacity_;
  delete[] data_;
  data_ = new Complex [capacity_];
  for (std::ptrdiff_t i = 0; i < size_; i++) {
    data_[i] = rhs.data_[i];
  }
  return *this;
}

void Stackarr::push(const Complex &rhs) {
  size_++;
  if (capacity_ == size_){
    data_ = new Complex [capacity_];
    capacity_ = 2 * size_;
  }
  data_[size_ - 1] = rhs;
}

void Stackarr::pop() {
  if (size_ == 0) throw std::runtime_error("cannot pop value: stack is empty");
  size_--;
}

bool Stackarr::empty() const {
  if (size_ == 0) return true;
  return false;
}

Complex Stackarr::top() const {
  if (size_ == 0) throw std::runtime_error("cannot get top value: stack is empty");
  return data_[size_ - 1];
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
