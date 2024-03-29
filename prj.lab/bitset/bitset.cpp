//
// Created by user on 18.03.2024.
//
#include <bitset/bitset.hpp>
#include <stdexcept>

BitSet::BitSet(BitSet &&other) noexcept {
  std::swap(bits, other.bits);
  std::swap(size, other.size);
}

BitSet &BitSet::operator=(const BitSet &other) {
  if (this == &other) return *this;
  for (size_t i = 0; i < size; ++i)
    bits[i] = other.bits[i];
  return *this;
}
BitSet &BitSet::operator=(BitSet && other) noexcept{
  std::swap(*this, other);
  other.Clear();
  return *this;
}
BitSet::~BitSet() {
  Clear();
}


void BitSet::Resize(int32_t newSize) {
  bits.resize(newSize);
  size = newSize;
}

void BitSet::Set(const int32_t i, const bool val) {
  if (i >= size)
    throw std::out_of_range("BitSet::Set");
  bits[i / 32] |= 1 << (i % 32);
}
bool BitSet::Get(const int32_t i) const{
  if (i >= size)
    return false;
  return (bits[i / 32] & (1 << (i % 32))) > 0;
}

BitSet &BitSet::operator~() {
  BitSet a(*this);
  a.Fill(1);
  return operator^=(a);
}
void BitSet::Fill(const bool value) noexcept {
  for (unsigned int & bit : bits) {
    bit = value;
  }
}
BitSet &BitSet::operator&=(const BitSet &other) {
  if (size != other.size) {
    throw std::runtime_error("Sizes of bitsets must be equal");
  }
  for (int i = 0; i < size; ++i) {
    bits[i] &= other.bits[i];
  }
  return *this;
}
BitSet &BitSet::operator|=(const BitSet &other) {
  if (size != other.size) {
    throw std::runtime_error("Sizes of bitsets must be equal");
  }
  for (int i = 0; i < size; ++i) {
    bits[i] |= other.bits[i];
  }
  return *this;
}
BitSet &BitSet::operator^=(const BitSet &other) {
  if (size != other.size) {
    throw std::runtime_error("Sizes of bitsets must be equal");
  }
  for (int i = 0; i < size; ++i) {
    bits[i] ^= other.bits[i];
  }
  return *this;
}
void BitSet::Clear() {
  for (auto &bit : bits)
    bit = 0;
  size = 0;
}
bool BitSet::operator==(const BitSet &rhs) const noexcept {
  for (size_t i = 0; i < size; i++) {
    if (bits[i] != rhs.bits[i])
      return false;
  }
  return true;
}


