//
// Created by user on 05.02.2024.
//
#include <stackarr/stackarr.hpp>
#include <stdexcept>

Stackarr::Stackarr() {
  size_ = 0;
  capacity_ = 10;
  data_ = new Complex[capacity_];
}
Stackarr::Stackarr(const Stackarr &rhs) {
  size_ = rhs.size_;
  if (size_ > capacity_){
    capacity_ = 2 * size_;
    data_ = new Complex [capacity_];
  }
  for (std::ptrdiff_t i = 0; i < size_; ++i)
    data_[i] = rhs.data_[i];
}

Stackarr::~Stackarr() {
  delete[] data_;
}

Stackarr &Stackarr::operator=(const Stackarr &rhs) {
  size_ = rhs.size_;
  if (size_ > capacity_){
    capacity_ = 2 * size_;
    delete[] data_;
    data_ = new Complex [capacity_];
  }
  for (std::ptrdiff_t i = 0; i < size_; i++) {
    data_[i] = rhs.data_[i];
  }
  return *this;
}

void Stackarr::push(const Complex &rhs) {
  size_++;
  if (capacity_ == size_ + 1){
    capacity_ = 2 * size_;
    auto* d = new Complex[capacity_ * 2];
    std::copy(data_, data_ + size_, d);
    std::swap(data_, d);
    delete[] d;
  }
  data_[size_ - 1] = rhs;
}

void Stackarr::pop() noexcept{
  //if (size_ == 0) throw std::runtime_error("cannot pop value: stack is empty");
  size_--;
}

bool Stackarr::empty() const noexcept{
  if (size_ == 0) return true;
  return false;
}

const Complex Stackarr::top() const {
  if (size_ == 0) throw std::runtime_error("cannot get top value: stack is empty");
  return data_[size_ - 1];
}
void Stackarr::clear() noexcept {
  size_ = 0;
}
