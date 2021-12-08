#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Node {
 private:
	Node* tail;
	T data;
 public:
	Node() {
		tail = nullptr;
	}
	Node(T in) {
		data = in;
		tail = nullptr;
	}
	/*
	~Node() {
		(*this).clear();
	}*/
	void operator=(Node in) {
		data = in.data;
	}
	void clear() {
		if (this->tail) {
			delete this;
			this->tail->clear();
				
		}
		else {
			delete this;
		}
	}
	void append(T in) {
		if (this->tail) {
			tail->append(in);
		}
		else {
			Node<T>* tmp = new Node(in);
			this->tail = tmp;
		}
	}
	void prepend(T in) {
		Node<T>* tmp = new Node(this->data);
		tmp->tail = this->tail;
		this->data = in;
		this->tail = tmp;
	}
	void add(T in) {
		if (this->tail && in>this->data) {
			this->tail->add(in);
		}
		else if (this->tail)
			this->prepend(in);
		else {
			this->append(in);
		}
	}	
	vector<T> output() {
		static vector<T> tmp;
		vector<T> result;
		if(this->tail) {
			tmp.push_back(this->data);
			return this->tail->output();
		}
		else {
			tmp.push_back(this->data);
			result.resize(tmp.size());
			for (unsigned int i=0; i<tmp.size(); i++) {
				result[i] = tmp[i];
			}
			tmp.resize(0);
			return result;
		}		
	}
};
template<typename T>
class LinkedList {
 private:
 	int s;
 	Node<T> root;
 public:
 	LinkedList() {
 		size=0;
 	};
 	LinkedList(T in) {
 		Node<T> tmp(in);
 		s = 1;
 		root = tmp; 
 	}
 	int size() {
 		return s;
 	}
 	void prepend(T in) {
 		s++;
 		root.prepend(in);
 	}
 	void append(T in) {
 		s++;
 		root.append(in);
 	}
 	void add(T in) {
 		s++;
 		root.add(in);
 	}
 	void clear() {
 		s = 0;
 		root.clear();
 	}		
};


int main() {
	LinkedList<int> l1(5);
	l1.add(7);
	l1.add(10);
	cout << l1.size();
}