#ifndef NODE_H
#define NODE_H

template <class T>
class node {
    public:
        node(T value);
        ~node() { }
        node* next() { return this->_next; }
        node* prev() { return this->_prev; }
        T value() { return this->_value; }
        void setNext(node* toSet) { this->_next = toSet; }
        void setPrev(node* toSet) { this->_prev = toSet; }
    private:
        T _value;
        node* _next;
        node* _prev;
};

template <class T>
node<T>::node(T value) {
    this->_value = value;
    this->_next = nullptr;
    this->_prev = nullptr;
}

#endif //NODE_H
