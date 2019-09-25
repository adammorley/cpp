template <class T>
linkedList<T>::linkedList(T value) {
    this->_size = 1;
    this->_head = new (std::nothrow) node<T>(value);
    assert(this->_head != nullptr);
}

template <class T>
linkedList<T>::~linkedList() {
    node<T>* cur = this->_head;
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
    node<T>* cur = this->_head;
    while (cur->next() != nullptr) {
        cur = cur->next();
    }
    cur->setNext(new (std::nothrow) node<T>(value));
    assert(cur->next() != nullptr);
    this->_size++;
}

template <class T>
unsigned int linkedList<T>::del(T value) {
    unsigned int size = this->size();
    node<T>* cur = this->_head;
    while (cur->next() != nullptr) {
        if (cur->value() == value) {
            if (cur->prev() == nullptr) { // head
                this->_head = cur->next();
            } else if (cur->next() == nullptr) { // tail
                cur->prev()->setNext(nullptr);
            } else { // middle
                node<T>* t = cur->prev();
                cur->prev()->setNext(cur->next());
                cur->next()->setPrev(t);
            }
            delete cur;
            this->_size--;
        }
        cur = cur->next();
    }
    return size - this->size();
}
