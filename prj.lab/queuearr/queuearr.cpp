//
// Created by user on 26.02.2024.
//
#include "queuearr.hpp"

QueueArr::QueueArr() {
  head_ = 0;
  tail_ = 0;
  capacity_ = 10;
  data_ = new Complex[capacity_];
}

QueueArr::QueueArr(const QueueArr &) {

}

QueueArr::~QueueArr() {
  delete data_;
}

Complex QueueArr::Top() {
  return data_[head_];
}

const Complex QueueArr::Top() const {
  return data_[head_];
}

bool QueueArr::IsEmpty() const noexcept {
  if (head_ == tail_) return true;
  return false;
}

void QueueArr::Push(const Complex &rhs) {
  // дописать
  if (tail_ == capacity_) {
    if (head_ != 0) {
      tail_ = tail_ % capacity_;
      data_[tail_] = rhs;
      tail_++;
    }
    else {
      auto* temp = new Complex[capacity_ * 2];
      std::copy(data_, data_ + capacity_, temp);
      std::swap(data_, temp);
      delete[] temp;
      capacity_ *= 2;
      data_[tail_] = rhs;
    }
  }
  /*else if (tail_ + 1 == head_){

  }*/
  else{
    data_[tail_] = rhs;
    tail_++;
  }
}

void QueueArr::Pop() noexcept {
  if (!IsEmpty()){
    if (head_ == capacity_){

    }
  }
  head_++;
}

QueueArr& QueueArr::operator=(const QueueArr &rhs) {
  return *this;
}

