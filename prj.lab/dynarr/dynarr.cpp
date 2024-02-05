#include <dynarr/dynarr.hpp>
#include <stdexcept>

DynArr::DynArr(const DynArr &a) {
  capacity_ = (capacity_ > 2 * a.size_ ? capacity_ : 2 * a.size_);
  size_ = a.size_;
  data_ = new float [capacity_];
  for (std::ptrdiff_t i = 0; i < size_; ++i)
    data_[i] = a.data_[i];
}

DynArr::DynArr(const ptrdiff_t size) {
  if (size <= 0) throw std::runtime_error("size <= 0");
  else {
    if (2 * size > capacity_) capacity_ = 2 * size;
    size_ = size;
    data_ = new float[capacity_];
    for (std::ptrdiff_t i = 0; i < size_; ++i) data_[i] = 0;
  }
}

DynArr &DynArr::operator=(const DynArr &rhs) {
  if (rhs.size_ > capacity_ || 4 * rhs.size_ < capacity_) {
    capacity_ = 2 * rhs.size_;
    size_ = rhs.size_;
    delete[] data_;
    data_ = new float[capacity_];
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

void DynArr::Resize(const std::ptrdiff_t size) {
  if (size <= 0) throw std::runtime_error("size <= 0");
  else {
    if (size > capacity_) {
      capacity_ = 2 * size;
      float *newData = new float[size];
      for (std::ptrdiff_t ind = 0; ind < size_; ind++) newData[ind] = data_[ind];
      for (std::ptrdiff_t ind = size_; ind < size; ind++) newData[ind] = 0;
      delete[] data_;
      data_ = newData;
    } else if (size > size_) {
      for (std::ptrdiff_t ind = size_; ind < size; ind++) data_[ind] = 0;
    }
    size_ = size;
  }
}
float &DynArr::operator[](const std::ptrdiff_t idx) {
  if (idx < 0 || idx > size_) throw std::runtime_error("invalid index");
  else return data_[idx];
}
const float &DynArr::operator[](const std::ptrdiff_t idx) const {
  if (idx < 0 || idx > size_) throw std::runtime_error("invalid index");
  else return data_[idx];
}
