#ifndef NODE_H
#define NODE_H

template <class T>
class node {
    public:
        node(T value);
        ~node() { }
        node* next() { return this->next_; }
        node* prev() { return this->prev_; }
        T value() { return this->value_; }
        void setNext(node* toSet) { this->next_ = toSet; }
        void setPrev(node* toSet) { this->prev_ = toSet; }
    private:
        T value_;
        node* next_;
        node* prev_;
};

template <class T>
node<T>::node(T value) {
    this->value_ = value;
    this->next_ = nullptr;
    this->prev_ = nullptr;
}

#endif //NODE_H
