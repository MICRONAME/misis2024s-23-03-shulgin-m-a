//
// Created by user on 05.02.2024.
//
#include <stackarr/stackarr.hpp>
#include <stdexcept>

StackArr::StackArr() {
  size_ = -1;
  capacity_ = 10;
  data_ = new Complex[capacity_];
}
StackArr::StackArr(const StackArr &rhs) {
  if (!rhs.IsEmpty()) {
    size_ = rhs.size_;
    if (size_ > capacity_) {
      capacity_ = 2 * size_;
      data_ = new Complex[capacity_];
    }
    for (std::ptrdiff_t i = 0; i <= size_; ++i)
      data_[i] = rhs.data_[i];
  }
}

StackArr::~StackArr() {
  delete[] data_;
}

StackArr &StackArr::operator=(const StackArr &rhs) {
  if (this != &rhs) {
    size_ = rhs.size_;
    if (size_ > capacity_) {
      capacity_ = 2 * size_;
      delete[] data_;
      data_ = new Complex[capacity_];
    }
    for (std::ptrdiff_t i = 0; i <= size_; i++) {
      data_[i] = rhs.data_[i];
    }
  }
  return *this;
}

void StackArr::Push(const Complex &rhs) {
  size_++;
  if (capacity_ == size_ + 1){
    capacity_ = 2 * size_;
    auto* d = new Complex[capacity_ * 2];
    std::copy(data_, data_ + size_, d);
    std::swap(data_, d);
    delete[] d;
  }
  data_[size_] = rhs;
}

void StackArr::Pop() noexcept{
  if (size_ != -1)
    size_--;
}

bool StackArr::IsEmpty() const noexcept{
  if (size_ == -1) return true;
  return false;
}

const Complex& StackArr::Top() const {
  if (size_ == -1) throw std::runtime_error("cannot get Top value: stack is empty");
  return data_[size_];
}
void StackArr::Clear() noexcept {
  size_ = -1;
}
Complex &StackArr::Top() {
  if (size_ == -1) throw std::runtime_error("cannot get Top value: stack is empty");
  return data_[size_];
}
