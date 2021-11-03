#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class LinkedList {
 private:
	LinkedList* tail;
	T data;
 public:
	LinkedList() {
		tail = nullptr;
	}
	LinkedList(T in) {
		data = in;
		tail = nullptr;
	}
	void operator=(LinkedList in) {
		data = in.data;
	}
	void remove(LinkedList<T>* in=nullptr) {
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
			LinkedList<T>* tmp = new LinkedList(in);
			this->tail = tmp;
		}
	}
	void prepend(T in) {
		LinkedList<T>* tmp = new LinkedList(this->data);
		tmp->tail = this->tail;
		this->data = in;
		this->tail = tmp;
	}
	void sorpend(T in) {
		if (this->tail && in>this->data) {
			this->tail->sorpend(in);
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


int main() {
	LinkedList<int> root(1);
	root.sorpend(5);
	root.sorpend(10);
	root.sorpend(19);
	root.sorpend(20);
	root.sorpend(6);
	root.sorpend(22);
	vector<int> s;
	s = root.output();
	for (unsigned int i=0; i<s.size(); i++)
		cout << s[i] << endl;
}