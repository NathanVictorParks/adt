#include "linkedlist.h"

template<typename T>
LinkedList<T>::LinkedList(): Node<T>::Node() {
    s = 0;
}

template<typename T>
LinkedList<T>::LinkedList(T in): Node<T>::Node(in) {
    s = 1;
}

template<typename T>
int LinkedList<T>::size() {
    return s;
}

template<typename T>
void LinkedList<T>::append(T in) {
    Node<T>::append(in);
    s += 1;
}

template<typename T>
void LinkedList<T>::prepend(T in) {
    Node<T>::prepend(in);
    s += 1;
}

template<typename T>
void LinkedList<T>::add(T in) {
    Node<T>::add(in);
    s += 1;
}
