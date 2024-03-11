//
// Created by user on 26.02.2024.
//
#include <queuearr/queuearr.hpp>
#include <stdexcept>

QueueArr::QueueArr() {
  head_ = 0;
  tail_ = 1;
  capacity_ = 10;
  data_ = new Complex[capacity_];
}

QueueArr::QueueArr(const QueueArr &rhs){
  if (!rhs.IsEmpty()){
    data_ = new Complex[rhs.capacity_];
    for (std::ptrdiff_t i = rhs.head_; i < rhs.tail_; i++) {
      data_[i - rhs.head_] = rhs.data_[i];
    }
    tail_ = rhs.tail_;
    capacity_ = rhs.capacity_;
    head_ = 0;
  }
}

QueueArr::~QueueArr() {
  delete[] data_;
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
  if (head_ == tail_ - 1) return true;
  return false;
}

void QueueArr::Push(const Complex &rhs) {
  //need to fix circle moving inside queue
  if (head_ != tail_ % capacity_){
    data_[(tail_ - 1) % capacity_] = rhs;
    tail_++;
  }
  else
  {
    auto* ndata = new Complex[capacity_ * 2];
    for (std::ptrdiff_t i = head_; i < capacity_; i++) {
      ndata[i - head_] = data_[i];
    }
    for (std::ptrdiff_t i = capacity_ - tail_ % capacity_ + 1; i < tail_; i++) {
      ndata[i - head_] = data_[i % capacity_];
    }
    std::swap(ndata, data_);
    delete[] ndata;
    capacity_ *= 2;
    head_ = 0;
    data_[tail_ - 1] = rhs;
    tail_++;
  }
}

void QueueArr::Pop() noexcept {
  // проверить
  if (head_ != (tail_ - 1) % capacity_){
    head_++;
    head_ %= capacity_;
  }
}

QueueArr& QueueArr::operator=(const QueueArr &rhs) {
  if (this != &rhs){
    if (!rhs.IsEmpty()){
      if (rhs.capacity_ > capacity_) {
        delete[] data_;
        data_ = new Complex[rhs.capacity_];
        for (std::ptrdiff_t i = rhs.head_; i < rhs.tail_; i++) {
          data_[i - rhs.head_] = rhs.data_[i];
        }
        tail_ = rhs.tail_;
        capacity_ = rhs.capacity_;
        head_ = 0;
      }
      else{
        for (std::ptrdiff_t i = rhs.head_; i < rhs.tail_; i++) {
          data_[i - rhs.head_] = rhs.data_[i];
        }
        tail_ = rhs.tail_;
        capacity_ = rhs.capacity_;
        head_ = 0;
      }
    }
  }
  return *this;
}

