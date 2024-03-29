// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef BITSET_BITSET_HPP_20240318
#define BITSET_BITSET_HPP_20240318

#include <cstdint>
#include <iosfwd>
#include <vector>

class BitSet {
 public:
  BitSet() = default;

  BitSet(const BitSet& other) : bits(other.bits), size(other.size) {}

  explicit BitSet(int32_t n) : bits(n / 32 + (n % 32 > 0)), size(n) {}

  BitSet(BitSet&&) noexcept ;

  BitSet& operator=(const BitSet&);

  BitSet& operator=(BitSet&&) noexcept ;

  ~BitSet();

  [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;

  [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept {return !operator==(rhs); }

  [[nodiscard]] int32_t Size() const noexcept { return size; }

  void Resize(const int32_t size); // 0 < size

  [[nodiscard]] bool Get(const int32_t idx) const;

  void Set(const int32_t idx, const bool val);

  void Fill(const bool val) noexcept;

  BitSet& operator&=(const BitSet& rhs);

  BitSet& operator|=(const BitSet& rhs);

  BitSet& operator^=(const BitSet& rhs);

  BitSet& operator~();

  void Clear();

  // ? operator[](const int32_t) - what can return
  // std::ostream& WriteTxt(std::ostream&)
  // std::ostream& WriteBinary(std::ostream&)
  // std::istream& ReadTxt(std::istream&)
  // std::istream& RaadBinary(std::istream&)
 private:
  std::int32_t size = 0;
  std::vector<uint32_t> bits;
};

// std::ostream& operaror<<(std::ostream&, const BitSet&);
// std::istream& operaror>>(std::istream&, BitSet&);

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
  BitSet answer(lhs);
  answer &= rhs;
  return answer;
}

[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
  BitSet answer(lhs);
  answer |= rhs;
  return answer;
}

[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
  BitSet answer(lhs);
  answer ^= rhs;
  return answer;
}

#endif