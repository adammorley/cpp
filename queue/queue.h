#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class queue {
 public:
  queue(int sz);
  ~queue() { delete[] queue_; };
  void Enqueue(T value);
  T Dequeue();
  bool full() const { return (back_ == size_); }
  bool empty() const { return (front_ == back_); }
  int size() const { return size_; }
  int count() const { return back_; }
 private:
  int front_;
  int back_;
  int size_;
  T* queue_;
};

#include "queue.cc"

#endif //QUEUE_H
