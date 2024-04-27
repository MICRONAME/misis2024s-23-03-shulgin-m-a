//
// Created by user on 05.02.2024.
//
#include <stackarr/stackarr.hpp>
#include <stdexcept>

StackArr::StackArr(const StackArr &rhs)
  : size_(rhs.size_) {
    if (!rhs.IsEmpty()) {
      capacity_ = ((size_ + 1) / 4 + 1) * 4;
      data_ = new Complex[capacity_];
      std::copy(rhs.data_, rhs.data_ + size_ + 1, data_);
    }
}

StackArr::~StackArr() {
  delete[] data_;
}

StackArr &StackArr::operator=(const StackArr &rhs) {
  if (this != &rhs) {
    if (rhs.IsEmpty()) {
      Clear();
    }
    if (capacity_ <= rhs.size_) {
      capacity_ = (rhs.size_ + 4) / 4 * 4;
      Complex* buf = new Complex[capacity_];
      std::swap(data_, buf);
      delete[] buf;
    }
    size_ = rhs.size_;
    std::copy(rhs.data_, rhs.data_ + size_ + 1, data_);
  }
  return *this;
}

void StackArr::Push(const Complex &rhs) {
  if (nullptr == data_) {
    capacity_ = 1;
    data_ = new Complex[capacity_];
  } else if (capacity_ == size_ + 1) {
    auto buf = new Complex[capacity_ * 2];
    std::copy(data_, data_ + capacity_, buf);
    std::swap(data_, buf);
    delete[] buf;
    capacity_ *= 2;
  }
  data_[++size_] = rhs;
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
StackArr::StackArr(StackArr && rhs) noexcept {
  if (!rhs.IsEmpty())
    std::swap(*this, rhs);
}
StackArr &StackArr::operator=(StackArr && rhs) noexcept {
  if (this != &rhs){
    if (!rhs.IsEmpty()){
      std::swap(*this, rhs);
    }
    else
      Clear();
  }
  return *this;
}
