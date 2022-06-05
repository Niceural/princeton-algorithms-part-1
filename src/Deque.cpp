#include "../include/week2/Deque.h"

template <typename T>
Deque<T>::Deque(): m_size(0), m_front(nullptr), m_back(nullptr) {}

template <typename T>
Deque<T>::~Deque() {
    if 
}

template <typename T>
void Deque<T>::pushFront(const T &data) {
    Node<T> *front = new Node<T>(data);
    m_front->prev = front;
    front->next = m_front;
    m_front = front;
    m_size++;
}

template <typename T>
void Deque<T>::pushBack(const T &data) {
    Node<T> *back = new Node<T>(data);
    m_back->next = back;
    back->prev = m_back;
    m_back = back;
    m_size++;
}

template <typename T>
void Deque<T>::popFront() {
    // stop if list is empty
    if (m_front == nullptr) return;
    //store the front node in a temporary variable
    Node<T> *temp = m_front;
    // set the front node to point to the 2nd node
    m_front = m_front->next;
    // deallocate the memory of temp var
    delete temp;
    // set prev of m_front to null
    m_front->prev = nullptr;
    m_size--;
}

template <typename T>
void Deque<T>::popBack() {
    // stop if list is empty
    if (m_back == nullptr) return;
    // store the back node in a temporary variable
    Node<T> *temp = m_back;
    // set the back node to the 2nd last node
    m_back = m_back->prev;
    // deallocate the memory of the temp var
    delete temp;
    // set next of the back node to null
    m_back->next = nullptr;
    m_size--;
}



template class Deque<int>;