#pragma once

#include "dllist.h"

template<class T>
class List<T>::ReverseIterator {
private:
	Node<T> *current;

public:
	//default + parameterized constructor
	ReverseIterator(Node<T> *curr = nullptr) : current(curr) {}
	//copy constructor, uses COPY-SWAP-IDIOM METHOD
	//which is explained in node.h file
	ReverseIterator(const ReverseIterator& right) : current(right.current) {}

public:
	//pre-increment
	ReverseIterator& operator++() {
		if (current)
			current = current->prev;
		return *this;
	}
	//post-increment (uses dummy argument)
	ReverseIterator operator++(int) {
		List<T>::ReverseIterator temp = *this;
		++(*this);
		return temp;
	}
	//pre-decrement
	ReverseIterator& operator--() {
		if (current)
			current = current->next;
		return *this;
	}
	//post-decrement (uses dummy argument)
	ReverseIterator operator--(int) {
		List<T>::ReverseIterator temp = *this;
		--(*this);
		return temp;
	}

	//inlined for efficiency
	inline bool operator==(const ReverseIterator& right) const { return (current == right.current); }
	inline bool operator!=(const ReverseIterator& right) const { return (current != right.current); }

	inline T& operator*() const { return current->data; }

	//part of COPY-SWAP-IDIOM, explained in node.h file
	friend void swap(ReverseIterator& first, ReverseIterator& second) {
		using std::swap;
		swap(first.current, second.current);
	}

	//uses COPY-SWAP-IDIOM, explained in node.h file
	ReverseIterator& operator=(ReverseIterator right) {
		swap(*this, right);
		return *this;
	}

	inline bool isNull() const { return (current == nullptr); }
	inline Node<T>*& getCurrent() const { return current; }
};
