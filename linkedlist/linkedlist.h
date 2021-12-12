#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.cc"

template<typename T>
class LinkedList: public Node<T> {
 
 private:
   
   int s;
 
 public:
   
   LinkedList();

   LinkedList(T in);

   int size();

   void append(T in);

   void prepend(T in);

   void add(T in);

};

#endif
