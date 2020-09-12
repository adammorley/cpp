#ifndef SORT_H
#define SORT_H

template <class T>
class sort {
 public:
  sort(T* values, unsigned int len);
  ~sort() { delete[] sorted_; }
  T* Sorted() { return this->sorted_; }
  unsigned int count() { return count_; }
private:
  bool done_;
  unsigned int count_;
  T* sorted_;
  T* merge(T* ptr0, T* ptr1, unsigned int ptr0L, unsigned int ptr1L);
  T* mergeSort(T* ptr, unsigned int len);
};

#include "sort.cc"

#endif //SORT_H
