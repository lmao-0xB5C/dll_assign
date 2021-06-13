#pragma once

#include <algorithm>

template<class T>
class Node {
public:
	//default constructor
	Node();
	//Parameterized constructor
	Node(Node<T> *_next, Node<T> *_prev, T _data);
	/*
		copy constructor, the way I have used it with operator= is called 
		copy-swap-idiom which is an exception safe way of copying objects
		otherwise if an exception is thrown while copying the data, our new
		object's data can be damaged. This prevents that.
		This uses two methods, swap and operator=
	*/
	Node(const Node<T>& right);

public:
	/*
		swap function is used in the copy-swap-idiom
		this is made a friend so that it can be found
		during the ADL or Argument Dependent Lookup
		which is done below by (using std::swap).
		It's friend hence implemented here, for consistency.
		Since std::swap() cannot return "failure", and we are not allowed to throw exception
		in our overload, so swap() overload will always succeed.
		By requiring that swap does not throw, the operator= is thus exception safe 
		: either the object is completely copied successfully, or the left - hand side is left unchanged.
	*/
	friend void swap(Node& first, Node& second) {
		using std::swap; //ADL
		swap(first.next, second.next);
		swap(first.prev, second.prev);
		swap(first.data, second.data);
	}

	//implementation below
	Node<T>& operator=(Node<T> right);

public:
	Node<T> *next, *prev;
	T data;
};

template<typename T>
Node<T>::Node(): next(nullptr), prev(nullptr) {}

template<typename T>
Node<T>::Node(Node<T> *_next, Node<T> *_prev, T _data): next(_next), prev(_prev), data(_data) {}

template<typename T>
Node<T>::Node(const Node<T>& right) : next(right.next), prev(right.prev), data(right.data) {}

/*
	This is an exception safe assignment operator
	It uses the swap function to make sure that NO
	"bad" copy occurs, as it doesnot change the state of *this,
	in which case the object might become un-useable and may even crash the program
	to make it exception safe we have to make a copy of the parameter first and then call swap
	but to clean the code and reduce overhead caused by creating an object, we can simply pass parameter as a copy,
	which calls the respective copy constructor, this is also an OPTIMIZATION in this case
	Also works well with temporary objects
	It is also safe for self assignment, which is rare but can happen
*/
template<typename T>
Node<T>& Node<T>::operator=(Node<T> right) {
	swap(*this, right);
	return *this;
}