#ifndef QNODE_HPP
#define QNODE_HPP

template<typename T>
class QNode {
private:
    T element{};
    QNode<T>* next;
public:
    // Constructor.
    explicit QNode(T element);

    // Pre: -
    // Post: returns a pointer to the next node.
    QNode<T>* get_next();

    // Pre: -
    // Post: changes the pointer to the next pointer.
    void set_next(QNode<T>* new_next);

    // Pre: -
    // Post: returns the stored element.
    T get_element();

    // Destructor.
    ~QNode();
};

template<typename T>
QNode<T>::QNode(T element) {
    this->element = element;
    next = nullptr;
}

template<typename T>
QNode<T> *QNode<T>::get_next() {
    return next;
}

template<typename T>
void QNode<T>::set_next(QNode<T> *new_next) {
    next = new_next;
}

template<typename T>
T QNode<T>::get_element() {
    return element;
}

template<typename T>
QNode<T>::~QNode() {
    next = nullptr;
}

#endif //QNODE_HPP