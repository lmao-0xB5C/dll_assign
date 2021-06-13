#pragma once //to prevent multiple inclusions

#include <string>

class Item {
private:
	int price;
	std::string ID, name, category, company;

private:
	//used for printing, string passed by value, so that it isn't changed
	//permanently
	std::string stringPad(std::string str, char ch, int count) {
    	str.resize(count, ch);
    	return str;
	}

public:
	//default constructor
	Item();
	//parameterized constructor
	Item(int _price, std::string _ID, std::string _name, std::string _category, std::string _company);
	//copy constructor, works as part of COPY-SWAP-IDIOM, explained in node.h file
	Item(const Item& right);

public:
	//operator overloading for comparison used in sorting
	bool operator<(const Item& right);
	inline bool operator==(const Item& right) { return ID == right.ID; }

	//part of COPY-SWAP-IDIOM, explained in node.h
	//parameter by copy is an optimization here
	Item& operator=(Item right);
	
	//overloading for printing the item, friend as parameters more than one
	//and also because item class is to the right of ostream(cout), and operator works
	//like object.operator<<(....), by reference return allows cascading
	//friend so implemented here for consistency
	friend std::ostream& operator<<(std::ostream& stream, Item& right) {
		stream << right.stringPad(right.ID, ' ', 16)
			<< right.stringPad(right.name, ' ', 24)
			<< std::to_string(right.price) 
			<< std::string("\t\t")
			<< right.stringPad(right.category, ' ', 24)
			<< right.company;
		
		return stream;
	}
	
	//friend, so implemented here for consistency
	//part of COPY-SWAP-IDIOM, explained in node.h
	friend void swap(Item& left, Item& right) {
		using std::swap;
		swap(left.ID, right.ID);
		swap(left.price, right.price);
		swap(left.name, right.name);
		swap(left.category, right.category);
		swap(left.company, right.company);
	}
};