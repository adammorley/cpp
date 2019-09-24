#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class queue {
    public:
        queue(int sz);
        ~queue() { delete[] _queue; };
        void enqueue(T value);
        T dequeue();
        bool full() const { return (_back == _size); }
        bool empty() const { return (_front == _back); }
        int size() const { return _size; }
        int count() const { return _back; }
    private:
        int _front;
        int _back;
        int _size;
        T* _queue;
};

#include "queue.cc"

#endif //QUEUE_H
