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
			tail->append(in);
		}
		else {
			Node<T>* tmp = new Node(in);
			this->tail = tmp;
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


int main() {
	Node<int> root(1);
	root.append(5);
	vector<int> s;
	s = root.output();
	for (unsigned int i=0; i<s.size(); i++)
		cout << s[i] << endl;
}