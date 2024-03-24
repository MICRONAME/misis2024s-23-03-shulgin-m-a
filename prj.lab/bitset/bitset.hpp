//
// Created by user on 18.03.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_BITSET_BITSET_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_BITSET_BITSET_HPP_

#include <cstdint>
#include <vector>

class BitSet{
 public:
  BitSet() = default;
  BitSet(const BitSet&);
  BitSet(BitSet&&) noexcept ;
  [[maybe_unused]] explicit BitSet(int32_t&);
  BitSet& operator=(const BitSet&);
  BitSet& operator=(BitSet&&);
  ~BitSet();

  int32_t Size() const noexcept;
  void Resize();
  void Set(const int32_t idx, const bool val);
  void Get(const int32_t idx);
  BitSet& operator&(const BitSet&);
  BitSet& operator|(const BitSet&);
  BitSet& operator^(const BitSet&);
  BitSet& operator~();
  void Fill(const bool);

 private:
  int32_t size_{};
  std::vector<uint32_t> data_;
};


#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_BITSET_BITSET_HPP_
