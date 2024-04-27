//
// Created by user on 26.02.2024.
//
#include <queuearr/queuearr.hpp>
#include <stdexcept>

QueueArr::QueueArr() {
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
    return data_[(head_ + 1) % capacity_];
}

const Complex& QueueArr::Top() const {
  if (IsEmpty())
    throw std::out_of_range("Queue is empty");
  else
    return data_[(head_ + 1) % capacity_];
}

bool QueueArr::IsEmpty() const noexcept {
  // когда сравнялись он может быть и полный. возможно этот случай в пуше обработан, надо тесты
  if ((head_ + 1) % capacity_ == tail_) return true;
  return false;
}

void QueueArr::Push(const Complex &rhs) {
  //need to fix circle moving inside queue
  if (tail_ - head_ != -1 && tail_ - head_ != capacity_){
    data_[tail_] = rhs;
    tail_++;
    tail_ %= capacity_;
  }
  else
  {
    auto* ndata = new Complex[capacity_ * 2];
    std::copy(data_ + head_ + 1, data_ + capacity_, ndata);
    std::copy(data_, data_ + tail_, ndata + head_ + 1);
    std::swap(ndata, data_);
    delete[] ndata;
    data_[tail_] = rhs;
    tail_ = capacity_;
    capacity_ *= 2;
    head_ = -1;
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
QueueArr &QueueArr::operator=(QueueArr && rhs) noexcept {
  if (this != &rhs){
    std::swap(*this, rhs);
  }
  return *this;
}
QueueArr::QueueArr(QueueArr && rhs) noexcept {
  if (!rhs.IsEmpty()){
    std::swap(*this, rhs);
  }
}

