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
        unsigned int size() const { return size_; }
    private:
        node<T>* head_;
        unsigned int size_;
};

#include "linkedList.cc"

#endif //LINKEDLIST_H
