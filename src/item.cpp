#include "item.h"

#include <iostream>

//default constructor
//uses member initializer list, faster than assignment in body
Item::Item():price(0), ID(""), name(""), category(""), company("") {}

//parameterized constructor
Item::Item(int _price, std::string _ID, std::string _name, std::string _category, std::string _company)
	: price(_price), ID(_ID), name(_name), category(_category), company(_company) {}

//copy constructor, works as part of COPY-SWAP-IDIOM explained in node.h
Item::Item(const Item& right) 
	:ID(right.ID), price(right.price), name(right.name), category(right.category), company(right.company) {}

//compares two items based on ids
bool Item::operator<(const Item& right){
	if(ID.length() < right.ID.length())
		return true;
	if(ID.length() == right.ID.length() && ID < right.ID)
		return true;
	return false;
}

//part of COPY-SWAP-IDIOM, explained in node.h
Item& Item::operator=(Item right) {
	swap(*this, right);
	return *this;
}