#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Node {
 private:
 	int size;
	Node* tail;
	T data;
 public:
	Node() {
		size = 0;
		tail = nullptr;
	}
	Node(T in) {
		size=0;
		data = in;
		tail = nullptr;
	}
	void operator=(Node in) {
		data = in.data;
	}
	void remove(Node<T>* in=nullptr) {
		if (!in) {
			in = this;
		}
		if (in->tail) {
			delete &in;
			remove(in->tail);
			
		}
		else {
			delete &in;
		}
	}
	void append(T in) {
		if (this->tail) {
			(*tail).append(in);
		}
		else {
			Node<T>* tmp = new Node(in);
			this->tail = tmp;
		}
	}
};


int main() {
	Node<int> root(1);
	root.append(5);

}