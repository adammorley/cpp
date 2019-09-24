#include <assert.h>
#include <new>

template <class T>
T queue<T>::dequeue() {
    assert(!this->empty());
    T ret = this->_queue[_front];
    for (int i = this->_front + 1; i <= this->_back; i++) {
        this->_queue[i-1] = this->_queue[i];
    }
    this->_back = this->_back - 1;
    return ret;
}

template <class T>
void
queue<T>::enqueue(T value) {
    assert(!this->full());
    this->_queue[_back++] = value;
}

template <class T>
queue<T>::queue(int sz) {
    this->_size = sz;
    this->_front = 0;
    this->_back = 0;
    this->_queue = new (std::nothrow) T[this->_size];
    assert(this->_queue != NULL);
}
