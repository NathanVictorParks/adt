#include "node.h"


template<typename T>
Node<T>::Node() {
	
	tail = nullptr;
}

template<typename T>
Node<T>::Node(T in) {
	
	data = in;
	
	tail = nullptr;

}

/*
~Node() {
	(*this).clear();
}*/

template<typename T>
void Node<T>::operator=(Node in) {
	data = in.data;
}

template<typename T>
void Node<T>::clear() {
	
	if (this->tail) {
		
		delete this;
		
		this->tail->clear();
			
	}
	
	else {
		
		delete this;
	
	}
}

template<typename T>
void Node<T>::append(T in) {
	
	if (this->tail) {
		
		tail->append(in);
	
	}

	else {
		
		Node<T>* tmp = new Node(in);
		
		this->tail = tmp;
	
	}
}

template<typename T>
void Node<T>::prepend(T in) {
	
	Node<T>* tmp = new Node(this->data);
	
	tmp->tail = this->tail;
	
	this->data = in;
	
	this->tail = tmp;

}

template<typename T>
void Node<T>::add(T in) {
	
	if (this->tail && in>this->data) {
		
		this->tail->add(in);
	
	}
	
	else if (this->tail)
		
		this->prepend(in);
	
	else {
		
		this->append(in);
	}

}	

template<typename T>
std::vector<T> Node<T>::output() {
	
	static std::vector<T> tmp;
	
	std::vector<T> result;
	
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


