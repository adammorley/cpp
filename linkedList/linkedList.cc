#include <iostream>
#include <new>

template <class T>
linkedList<T>::linkedList(T value) {
    this->size_ = 1;
    this->head_ = new (std::nothrow) node<T>(value);
    assert(this->head_ != nullptr);
    this->tail_ = this->head_;
}

template <class T>
linkedList<T>::~linkedList() {
    node<T>* cur = this->head_;
    node<T>* n;
    while (cur != nullptr) {
        n = cur->next();
        delete cur;
        cur = n;
    }
}

template <class T>
void
linkedList<T>::Add(T value) {
    node<T>* cur = this->tail_;
    cur->setNext(new (std::nothrow) node<T>(value));
    assert(cur->next() != nullptr);
    this->tail_ = cur->next();
    this->size_++;
}

// returns the number of elements deleted
template <class T>
unsigned int linkedList<T>::Delete(T value) {
    unsigned int size = this->size();
    node<T>* cur = this->head_;
    while (cur->next() != nullptr) {
        if (cur->value() == value) {
            if (cur->prev() == nullptr) { // head
                this->head_ = cur->next();
            } else if (cur->next() == nullptr) { // tail
                cur->prev()->setNext(nullptr);
                this->tail_ = cur->prev();
            } else { // middle
                node<T>* t = cur->prev();
                cur->prev()->setNext(cur->next());
                cur->next()->setPrev(t);
            }
            delete cur;
            this->size_--;
        }
        cur = cur->next();
    }
    return size - this->size();
}

template <class T>
void linkedList<T>::Print() {
    node<T>* cur = this->head_;
    while (cur != nullptr) {
        std::cout << cur->value() << std::endl;
        cur = cur->next();
    }
}
