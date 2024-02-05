#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <cstddef>

class DynArr {
 public:

  ///DEFAULT CONSTRUCTOR
  DynArr() { size_ = 0; capacity_ = 10; data_ = new float[10]; }

  ///COPY CONSTRUCTOR
  DynArr(const DynArr& a);

  ///CONSTRUCTOR BY SIZE
  DynArr(const std::ptrdiff_t size);

  ///GETS SIZE VALUE
  [[nodiscard]] std::ptrdiff_t Size() const { return size_; }

  DynArr& operator= (const DynArr& rhs);

  ///RESIZE DYNARR
  void Resize(const std::ptrdiff_t size);

  ///GETS INDEXES
  float& operator[](const std::ptrdiff_t idx);
  const float& operator[](const std::ptrdiff_t idx) const;

  ///DESTRUCTOR
  ~DynArr() { delete[] data_; }

 private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 10;
  float* data_;
};

#endif //DYNARR_HPP
