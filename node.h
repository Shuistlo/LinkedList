#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// TODO your code for the Node class goes here:
// (Note the 'NodeIterator' class will report lots of errors until Node exists
template <typename T>
class Node {
       public:
	T data;
	Node<T>* previous;
	Node<T>* next;

	Node(const T dataIn) : data(dataIn) {
		previous = nullptr;
		next = nullptr;
	}

	~Node() {}

	void setNext(Node<T>* nN) {
		next = nN;  // on valgrind it will only run next(nN);
	};

	void setPrev(Node<T>* pN) {
		previous = pN;  // see note on setNext()
	};
};

template <typename T>
class NodeIterator {
       private:
	Node<T>* current;

       public:
	NodeIterator(Node<T>* currentIn) : current(currentIn) {}

	~NodeIterator() {}

	Node<T>* getNode() const { return current; }

	T& operator*() { return current->data; }

	const NodeIterator& operator++() {
		current = current->next;
		return *this;
	}
	NodeIterator operator++(int) {
		NodeIterator result = *this;
		++(*this);
		return result;
	}

	bool operator==(NodeIterator const & other) const {
		if (other.getNode() == current) {
			return true;
		}
		return false;
	}

	bool operator!=(NodeIterator const & other) const {
		return !(*this==other);
	}
	// TODO: complete the code for NodeIterator here
};

// do not edit below this line

#endif
