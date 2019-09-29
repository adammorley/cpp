#include <assert.h>
#include <new>

template <class T>
T stack<T>::pop() {
    assert(!this->empty());
    return this->stack_[--top_];
}

template <class T>
void
stack<T>::push(T value) {
    assert(!this->full());
    this->stack_[top_++] = value;
}

template <class T>
stack<T>::stack(int sz) {
    this->size_ = sz;
    this->top_ = 0;
    this->stack_ = new (std::nothrow) T[this->size_];
    assert(this->stack_ != nullptr);
}
