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

//QueueArr::QueueArr(const QueueArr &rhs) {

//}

QueueArr::~QueueArr() {
  delete[] data_;
}

Complex QueueArr::Top() {
  return data_[head_];
}

const Complex QueueArr::Top() const {
  return data_[head_];
}

bool QueueArr::IsEmpty() const noexcept {
  // когда сравнялись он может быть и полный. возможно этот случай в пуше обработан, надо тесты
  if (head_ == tail_) return true;
  return false;
}

void QueueArr::Push(const Complex &rhs) {
  // вроде как дописано
  //это случай когда хвост дошел до конца
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
  //это случай когда уже полная очередь
  else if (tail_ + 1 == head_){
    auto* temp = new Complex[capacity_ * 2];
    std::ptrdiff_t tempPointer = 0;
    for (std::ptrdiff_t i = head_; i < capacity_; i++){
      temp[tempPointer] = data_[i];
      tempPointer++;
    }
    for (std::ptrdiff_t i = 0; i < tail_; i++){
      temp[tempPointer] = data_[i];
      tempPointer++;
    }
    head_ = 0;
    tail_ = capacity_;
    capacity_ *= 2;
    delete[] temp;
  }
  // дефолтный пуш
  else{
    data_[tail_] = rhs;
    tail_++;
  }
}

void QueueArr::Pop() noexcept {
  // проверить
  if (!IsEmpty()){
    if (head_++ == capacity_){
      head_ = head_ % capacity_;
    }
    else
      head_++;
  }
}

QueueArr& QueueArr::operator=(const QueueArr &rhs) {
  return *this;
}

