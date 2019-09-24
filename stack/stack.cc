#include <assert.h>
#include <new>

template <class T>
T stack<T>::pop() {
    assert(!this->empty());
    return this->_stack[--_top];
}

template <class T>
void
stack<T>::push(T value) {
    assert(!this->full());
    this->_stack[_top++] = value;
}

template <class T>
stack<T>::stack(int sz) {
    this->_size = sz;
    _top = 0;
    _stack = new (std::nothrow) T[_size];
    assert(_stack != NULL);
}
