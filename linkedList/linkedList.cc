#include <new>

template <class T>
linkedList<T>::linkedList(T value) {
    this->size_ = 1;
    this->head_ = new (std::nothrow) node<T>(value);
    assert(this->head_ != nullptr);
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
linkedList<T>::add(T value) {
    node<T>* cur = this->head_;
    while (cur->next() != nullptr) {
        cur = cur->next();
    }
    cur->setNext(new (std::nothrow) node<T>(value));
    assert(cur->next() != nullptr);
    this->size_++;
}

template <class T>
unsigned int linkedList<T>::del(T value) {
    unsigned int size = this->size();
    node<T>* cur = this->head_;
    while (cur->next() != nullptr) {
        if (cur->value() == value) {
            if (cur->prev() == nullptr) { // head
                this->head_ = cur->next();
            } else if (cur->next() == nullptr) { // tail
                cur->prev()->setNext(nullptr);
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
