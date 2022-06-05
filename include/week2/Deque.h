#ifndef DEQUE_H
#define DEQUE_H

#include "Node.h"

template <typename T>
class Deque {
    int m_size;
    Node<T>* m_front;
    Node<T>* m_back;

public:
    Deque();
    ~Deque();
    bool isEmpty() const;
    int size() const;
    void pushFront(const T &);
    void pushBack(const T &);
    void popFront();
    void popBack();
    T getFront();
    T getBack();

    class iterator;
};

template <typename T>
class Deque<T>::iterator {

};

#endif // DEQUE_H