#include <assert.h>
#include <new>

template <class T>
T queue<T>::Dequeue() {
    assert(!this->empty());
    T ret = this->queue_[front_];
    for (int i = this->front_ + 1; i <= this->back_; i++) {
        this->queue_[i-1] = this->queue_[i];
    }
    this->back_ = this->back_ - 1;
    return ret;
}

template <class T>
void
queue<T>::Enqueue(T value) {
    assert(!this->full());
    this->queue_[back_++] = value;
}

template <class T>
queue<T>::queue(int sz) {
    this->size_ = sz;
    this->front_ = 0;
    this->back_ = 0;
    this->queue_ = new (std::nothrow) T[this->size_];
    assert(this->queue_ != nullptr);
}
