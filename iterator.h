#pragma once

#include "dllist.h"

template<class T>
class List<T>::ForwardIterator {
private:
	Node<T> *current;

public:
	//default + parameterized constructor
	ForwardIterator(Node<T> *curr = nullptr) : current(curr) {}
	//copy constructor, uses COPY-SWAP-IDIOM METHOD
	//which is explained in node.h file
	ForwardIterator(const ForwardIterator& right) : current(right.current) {}

public:
	//pre-increment
	ForwardIterator& operator++() {
		if (current)
			current = current->next;
		return *this;
	}
	//post-increment (uses dummy argument)
	ForwardIterator operator++(int) {
		List<T>::ForwardIterator temp = *this;
		++(*this);
		return temp;
	}
	//pre-decrement
	ForwardIterator& operator--() {
		if (current)
			current = current->prev;
		return *this;
	}
	//post-decrement (uses dummy argument)
	ForwardIterator operator--(int) {
		List<T>::ForwardIterator temp = *this;
		--(*this);
		return temp;
	}

	//inlined for efficiency, const functions so that they can't change anything
	inline bool operator==(const ForwardIterator& right) const { return (current == right.current); }
	inline bool operator!=(const ForwardIterator& right) const { return (current != right.current); }

	//dereference
	inline T& operator*() const { return current->data; }

	//part of COPY-SWAP-IDIOM, explained in node.h file
	friend void swap(ForwardIterator& first, ForwardIterator& second) {
		using std::swap;
		swap(first.current, second.current);
	}

	//uses COPY-SWAP-IDIOM, explained in node.h file
	ForwardIterator& operator=(ForwardIterator right) {
		swap(*this, right);
		return *this;
	}

	inline bool isNull() const { return (current == nullptr); }
	inline Node<T>*& getCurrent() { return current; }

};
