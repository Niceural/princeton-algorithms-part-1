#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node();
};

template <typename T>
Node<T>::Node(): prev(nullptr), next(nullptr) {}

#endif // NODE_H