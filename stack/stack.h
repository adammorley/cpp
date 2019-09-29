#ifndef STACK_H
#define STACK_H

template <class T>
class stack {
 public:
  stack(int sz);
  ~stack() { delete[] stack_; };
  void Push(T value);
  T Pop();
  bool full() const { return (top_ == size_); }
  bool empty() const { return (top_ == 0); }
  int size() const { return size_; }
  int count() const { return top_; }
private:
  int top_;
  int size_;
  T* stack_;
};

#include "stack.cc"

#endif //STACK_H
