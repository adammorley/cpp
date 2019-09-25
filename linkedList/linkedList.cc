template <class T>
linkedList<T>::linkedList(T value) {
    this->_size = 1;
    this->_head = new (std::nothrow) node<T>(value);
    assert(this->_head != NULL);
}

template <class T>
linkedList<T>::~linkedList() {
    node<T>* cur = this->_head;
    node<T>* n;
    while (cur != NULL) {
        n = cur->next();
        delete cur;
        cur = n;
    }
}

template <class T>
void
linkedList<T>::add(T value) {
    node<T>* cur = this->_head;
    while (cur->next() != NULL) {
        cur = cur->next();
    }
    cur->setNext(new (std::nothrow) node<T>(value));
    assert(cur->next() != NULL);
    this->_size++;
}

template <class T>
unsigned int linkedList<T>::del(T value) {
    unsigned int size = this->size();
    node<T>* cur = this->_head;
    while (cur->next() != NULL) {
        if (cur->value() == value) {
            if (cur->prev() == NULL) { // head
                this->_head = cur->next();
            } else if (cur->next() == NULL) { // tail
                cur->prev()->setNext(NULL);
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
