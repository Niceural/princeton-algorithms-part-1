#include "../include/week2/Deque.h"

template <typename T>
Deque<T>::Deque(): m_size(0), m_front(nullptr), m_back(nullptr) {}

template <typename T>
void Deque<T>::pushFront(const T &data) {
    Node<T> front;
    (*m_front).prev = &front;
    front.data = data;
    front.next = m_front;
    m_front = &front;
}