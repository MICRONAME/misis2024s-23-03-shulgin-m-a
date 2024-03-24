//
// Created by user on 18.03.2024.
//
#include <bitset/bitset.hpp>

BitSet::BitSet(const BitSet &rhs) {
  if (rhs.size_ != 0){
    size_ = rhs.size_;
    data_ = rhs.data_;
  }
}
BitSet::BitSet(BitSet && rhs) noexcept {
  if (rhs.size_ != 0){
    //std::swap(data_, rhs.data_);
    std::swap(size_, rhs.size_);
  }
}
/*
[[maybe_unused]] BitSet::BitSet(int32_t& rhs) {
  if (rhs != 0){

  }
}*/

BitSet &BitSet::operator=(const BitSet &rhs) {
  if (this != &rhs){

  }
  return *this;
}


