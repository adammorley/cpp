#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

template <class T>
class linkedList {
    public:
        linkedList(T value);
        ~linkedList();
        void add(T value);
        unsigned int del(T value);
        unsigned int size() const { return _size; }
    private:
        node<T>* _head;
        unsigned int _size;
};

#include "linkedList.cc"

#endif //LINKEDLIST_H
