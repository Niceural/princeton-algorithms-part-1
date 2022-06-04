#ifndef DEQUE_H
#define DEQUE_H

template <typename T>
class Deque {

public:
    Deque();
    ~Deque();
    bool isEmpty();
    int size();
    void addFront(T);
    void addBack(T);
    void removeFront();
    void removeBack();
    T getFront();
    T getBack();

    class iterator;
};

template <typename T>
class Deque<T>::iterator {

};

#endif // DEQUE_H