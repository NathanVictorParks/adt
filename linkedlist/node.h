#ifndef NODE_H
#define NODE_H

#include <vector>

template<typename T>
class Node {
 
 protected:
	
	Node* tail;
	
	T data;
 
 public:

 	Node();

 	Node(T in);

 	void operator=(Node in);

 	void clear();

 	void append(T in);

 	void prepend(T in);

 	void add(T in);

 	std::vector<T> output();

};

#endif	