#ifndef STACK_H
#define STACK_H

template <class T>
class stack {
    public:
        stack(int sz);
        ~stack() { delete[] _stack; };
        void push(T value);
        T pop();
        bool full() const { return (_top == _size); }
        bool empty() const { return (_top == 0); }
    private:
        int _top;
        int _size;
        T* _stack;
};

#include "stack.cc"

#endif //STACK_H
