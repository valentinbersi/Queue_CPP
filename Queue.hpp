#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <exception>
#include "QNode.hpp"

class EmptyException : public std::exception {
public:
    const char *what() const noexcept override {
        return "The queue is empty.";
    }
};

template<typename T>
class Queue {
private:
    QNode<T> *first_node;
    QNode<T> *last_node;
    size_t _size;

    const size_t EMPTY = 0;

public:
    // Constructor.
    Queue();

    // Copy constructor
    Queue(const Queue &queue);

    // Assignment operator
    [[nodiscard]] Queue<T> &operator=(const Queue &queue);

    // Pre: -
    // Post: adds the element at the end of the queue.
    void add(T new_element);

    // Pre: the queue can´t be empty.
    // Post: removes the first element and returns it.
    T remove();

    // Pre: the queue can´t be empty.
    // Post: returns the first element of the queue.
    [[nodiscard]] T first();

    // Pre: the queue can´t be empty.
    // Post: returns the last element in the queue.
    [[nodiscard]] T last();

    // Pre: -
    // Post: returns the number of elements in the queue.
    [[nodiscard]] size_t size();

    // Pre: -
    // Post: returns true if the queue is empty.
    [[nodiscard]] bool empty();

    // Destructor.
    ~Queue();
};

template<typename T>
Queue<T>::Queue() {
    first_node = nullptr;
    last_node = nullptr;
    _size = EMPTY;
}

template<typename T>
Queue<T>::Queue(const Queue &queue) {
    first_node = nullptr;
    last_node = nullptr;
    _size = EMPTY;

    QNode<T> *current_node = queue.first_node;

    while (current_node != nullptr) {
        add(current_node->get_element());
        current_node = current_node->get_next();
    }
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue &queue) {
    Queue<T> aux(queue);

    first_node = nullptr;
    last_node = nullptr;
    _size = EMPTY;

    QNode<T> *current_node = aux.first_node;

    while (current_node != nullptr) {
        add(current_node->get_element());
        current_node = current_node->get_next();
    }

    return *this;
}

template<typename T>
void Queue<T>::add(T element) {
    if (size() == EMPTY) {
        first_node = new QNode<T>(element);
        last_node = first_node;

    } else {
        auto *new_node = new QNode<T>(element);
        last_node->set_next(new_node);
        last_node = new_node;
    }

    _size++;
}

template<typename T>
T Queue<T>::remove() {
    if (empty()) throw EmptyException();

    QNode<T> *removed_node = first_node;
    first_node = removed_node->get_next();
    T removed_element = removed_node->get_element();
    delete removed_node;
    _size--;
    return removed_element;
}

template<typename T>
T Queue<T>::first() {
    if (empty()) throw EmptyException();

    return first_node->get_element();
}

template<typename T>
T Queue<T>::last() {
    if (empty()) throw EmptyException();

    return last_node->get_element();
}

template<typename T>
size_t Queue<T>::size() {
    return _size;
}

template<typename T>
bool Queue<T>::empty() {
    return _size == EMPTY;
}

template<typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        remove();
    }
}

#endif //QUEUE_HPP