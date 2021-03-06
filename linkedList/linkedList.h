#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

template <class T>
class linkedList {
 public:
  linkedList(T value);
  ~linkedList();
  void Add(T value);
  unsigned int Delete(T value);
  void Print();
  unsigned int size() const { return size_; }
private:
  node<T>* head_;
  node<T>* tail_;
  unsigned int size_;
};

#include "linkedList.cc"

#endif //LINKEDLIST_H
