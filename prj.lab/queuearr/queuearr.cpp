//
// Created by user on 26.02.2024.
//
#include <queuearr/queuearr.hpp>
#include <stdexcept>

QueueArr::QueueArr() {
  head_ = 0;
  tail_ = 0;
  capacity_ = 10;
  data_ = new Complex[capacity_];
}

QueueArr::QueueArr(const QueueArr &rhs){
  if (!rhs.IsEmpty()){
    capacity_ = rhs.capacity_;
    data_ = new Complex[rhs.capacity_];
    std::copy(rhs.data_, rhs.data_ + capacity_, data_);
    tail_ = rhs.tail_;
    head_ = rhs.head_;
  }
}

QueueArr::~QueueArr() {
  Clear();
}

Complex& QueueArr::Top() {
  if (IsEmpty())
    throw std::out_of_range("Queue is empty");
  else
    return data_[head_];
}

const Complex& QueueArr::Top() const {
  if (IsEmpty())
    throw std::out_of_range("Queue is empty");
  else
    return data_[head_];
}

bool QueueArr::IsEmpty() const noexcept {
  // когда сравнялись он может быть и полный. возможно этот случай в пуше обработан, надо тесты
  if (head_ == tail_) return true;
  return false;
}

void QueueArr::Push(const Complex &rhs) {
  //need to fix circle moving inside queue
  data_[tail_] = rhs;
  if (tail_ - head_ != -1 && tail_ - head_ != capacity_ - 1){
    tail_++;
    tail_ %= capacity_;
  }
  else
  {
    auto* ndata = new Complex[capacity_ * 2];
    for (std::ptrdiff_t i = head_; i < capacity_; i++) {
      ndata[i - head_] = data_[i];
    }
    for (std::ptrdiff_t i = 0; i <= tail_; i++) {
      ndata[i] = data_[i];
    }
    std::swap(ndata, data_);
    delete[] ndata;
    tail_ = capacity_;
    capacity_ *= 2;
    head_ = 0;
  }
}

void QueueArr::Pop() noexcept {
  head_++;
  head_ %= capacity_;
}

QueueArr& QueueArr::operator=(const QueueArr &rhs) {
  if (this != &rhs){
    if (!rhs.IsEmpty()){
      delete[] data_;
      data_ = new Complex[rhs.capacity_];
      capacity_ = rhs.capacity_;
      std::copy(rhs.data_, rhs.data_ + capacity_, data_);
      tail_ = rhs.tail_;
      head_ = rhs.head_;
    } else
      Clear();
  }
  return *this;
}

void QueueArr::Clear() noexcept {
  delete[] data_;
}

