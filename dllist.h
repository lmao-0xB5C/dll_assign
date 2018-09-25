#pragma once //to prevent multiple inclusions

#include "node.h"
#include "item.h"

#include <iostream>

//DOUBLY LINKED LIST ADT
template<class T>
class List : public Node<T> {
private:
	Node<T> *head, *tail;

private:
	//Forward declerations
	class ForwardIterator;
	class ReverseIterator;

public:
	//default constructor
	List();
	//copy constructor
	List(const List& right);
	//destructor, not in the submitted assignment
	~List();
=======
>>>>>>> parent of cc7244a... Added list destructor, which was missing from submitted assignment *sed*

public:
	//typedef is used at compile time, its an alias basically
	typedef ForwardIterator Iterator;
	typedef ReverseIterator Rev_Iterator;

public:
	//inlined for efficiency
	inline bool isEmpty() const { return (head == nullptr); }

	//const so it cannot be changed, and & as not to create a copy
	Node<T>* find(const T& element);

	void addToHead(const T& element);
	void addToTail(const T& element);

	void deleteFromHead();
	void deleteFromTail();
	void deleteElement(Iterator& itr);

	void insertBefore(Iterator& itr, const T& element);
	void insertAfter(Iterator& itr, const T& element);

	//this is NOT part of COPY-SWAP-IDIOM, its the function asked
	//in the assignment
	void swapElements(Iterator& itr_a, Iterator& itr_b);

	//part of COPY-SWAP-IDIOM, explained in node.h
	//friend so implemented here, for consistency
	friend void swap(List& first, List& second) {
		using std::swap; //ADL or Abstract data lookup
		swap(first.head, second.head);
		swap(first.tail, second.tail);
	}
	//part of COPY-SWAP-IDIOM, explained in node.h
	//passing parameter by copy is an optimization here
	List<T>& operator=(List<T> right) {
		swap(*this, right);
		return *this;
	}

	void sortList(Iterator& itr_a, Iterator& itr_b);

	//the return creates an object of respective iterator type
	//and uses returned node to construct it
	inline Iterator begin() { return head; }
	inline Iterator end() { return tail; }
	inline const Rev_Iterator rBegin() { return tail; }
	inline const Rev_Iterator rEnd() { return head; }
};

//default constructor
//uses member initializer list, faster than assignment in body
template<typename T>
List<T>::List(): head(nullptr), tail(nullptr) {}

//copy constructor, works as part of COPY-SWAP-IDIOM, explained in node.h
template<typename T>
List<T>::List(const List& right) : head(right.head), tail(right.tail) {}

template<typename T>
Node<T>* List<T>::find(const T& element) {

	//checks if list is empty or not, to prevent next
	//code from runnning if true
	if (isEmpty()) {
		std::cout << "List is Empty!\n";
		return nullptr;
	}
	Node<T> *hold = head;

	//traverses array and if element is found returns it,
	//else returns nullptr
	while (hold != nullptr) {
		if (hold->data == element)
			return hold;
		hold = hold->next;
	}
	std::cout << "Element not found!\n";
	return nullptr;
}

template<typename T>
void List<T>::addToHead(const T& element) {
	//if list is empty
	if (isEmpty()) {
		head = new Node<T>(nullptr, nullptr, element);
		tail = head;
	}
	else {
		Node<T> *temp = new Node<T>(head, nullptr, element);
		head->prev = temp;
		head = temp;
	}
}

template<typename T>
void List<T>::addToTail(const T& element) {
	//if list is empty
	if (isEmpty()) {
		head = new Node<T>(nullptr, nullptr, element);
		tail = head;
	}
	else {
		Node<T>* temp = new Node<T>(nullptr, tail, element);
		tail->next = temp;
		tail = temp;
	}
}

template<typename T>
void List<T>::deleteFromHead() {
	//if list is empty, prevents next code from running
	//efficient and doesn't crash
	if (isEmpty()) {
		std::cout << "List is Empty!\n";
		return;
	}
	//if one element
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<T> *hold = head;
		head = head->next;
		head->prev = nullptr;
		delete hold;
	}
	std::cout << "Item deleted!\n";
}

template<typename T>
void List<T>::deleteFromTail() {
	//checks if list is empty
	if (isEmpty()) {
		std::cout << "List is Empty!\n";
		return;
	}
	//if one element
	if (tail->prev == nullptr) {
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<T> *hold = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete hold;
	}
	std::cout << "Item deleted!\n";
}

template<typename T>
void List<T>::deleteElement(Iterator& itr) {
	//if list is empty
	if (isEmpty()) {
		std::cout << "List is Empty!\n";
		return;
	}
	//to make sure itr is valid
	if (!itr.isNull()) {
		if (itr.getCurrent() == head)
			deleteFromHead();
		else if (itr.getCurrent() == tail)
			deleteFromTail();
		else {
			Node<T> *hold = itr.getCurrent();
			itr.getCurrent()->prev->next = itr.getCurrent()->next;
			itr.getCurrent()->next->prev = itr.getCurrent()->prev;
			delete hold;
			std::cout << "Item deleted!\n";
		}
	}
	else
		std::cout << "Iterator is not correct!\n";
}

template<typename T>
void List<T>::insertBefore(Iterator& itr, const T& element) {
	if (isEmpty()) {
		std::cout << "List is Empty!\n";
		return;
	}
	//if current is head calls addToHead method
	if (!itr.isNull()) {
		if (itr.getCurrent() == head)
			addToHead(element);
		else {
			Node<T> *temp = new Node<T>(itr.getCurrent(), itr.getCurrent()->prev, element);
			itr.getCurrent()->prev->next = temp;
			itr.getCurrent()->prev = temp;
		}
	}
	else
		std::cout << "Iterator is not correct!\n";
}

template<typename T>
void List<T>::insertAfter(Iterator& itr, const T& element) {
	if (isEmpty()) {
		std::cout << "List is Empty!\n";
		return;
	}
	//if current is tail calls addToTail method
	if (!itr.isNull()) {
		if (itr.getCurrent() == tail)
			addToTail(element);
		else {
			Node<T> *temp = new Node<T>(itr.getCurrent()->next, itr.getCurrent(), element);
			itr.getCurrent()->next->prev = temp;
			itr.getCurrent()->next = temp;
		}
	}
	else
		std::cout << "Iterator is not correct!\n";
}

template<typename T>
void List<T>::swapElements(Iterator& itr_a, Iterator& itr_b) {
	if (isEmpty()) {
		std::cout << "List is Empty!\n";
		return;
	}

	//checks for iterator validity
	if(!itr_a.isNull() && !itr_b.isNull()){
		//These checks are for end and last elements
		if(itr_a.getCurrent() == head)
			head = itr_b.getCurrent();
		else if(itr_b.getCurrent() == head)
			head = itr_a.getCurrent();
		if(itr_a.getCurrent() == tail)
			tail = itr_b.getCurrent();
		else if(itr_b.getCurrent() == tail)
			tail = itr_a.getCurrent();

		//handles next pointers of node
		Node<T>* hold = itr_a.getCurrent()->next;
		if(hold != nullptr)
			hold->prev = itr_b.getCurrent();

		itr_a.getCurrent()->next = itr_b.getCurrent()->next;

		if(itr_b.getCurrent()->next != nullptr)
			itr_b.getCurrent()->next->prev = itr_a.getCurrent();

		itr_b.getCurrent()->next = hold;

		//handles prev pointers of node
		hold = itr_a.getCurrent()->prev;
		if(hold != nullptr)
			hold->next = itr_b.getCurrent();

		itr_a.getCurrent()->prev = itr_b.getCurrent()->prev;

		if(itr_b.getCurrent()->prev != nullptr)
			itr_b.getCurrent()->prev->next = itr_a.getCurrent();

		itr_b.getCurrent()->prev = hold;
	}
	else
		std::cout << "Iterators are not correct!\n";
}

template<typename T>
void List<T>::sortList(Iterator& itr_a, Iterator& itr_b) {

	//checks if iterators are in right order
	//checks if iterators point to a valid node or not
	if (!itr_a.isNull() && !itr_b.isNull()) {
		//sets starting and ending positions
		Iterator n = itr_b, start = itr_a;
		Iterator i = itr_a, j;
		//to start from next node
		i++;
		//to make sure it checks till the very first node
		start--;
		//to make sure end node is checked as well
		n++;
		//goes from itr_a->next to itr_b->next 
		for (; i != n; i++) {
			//data stored for comparison
			T temp = *i;
			j = i;
			--j;
			//until whole left "sorted" part has been traversed,
			//or temp is not greater than j's data
			while ((j != start) && (temp < *j)) {
				Iterator hold = j;
				hold++;
				*hold = *j;
				j--;
			}
			//special case where whole left "sorted" part was
			//traversed
			if (j != start) {
				Iterator hold = j;
				++hold;
				if (hold != nullptr)
					*hold = temp;
			}
			else {
				*itr_a = temp;
			}
		}
	}
	else
		std::cout << "Iterators are not correct!\n";
}