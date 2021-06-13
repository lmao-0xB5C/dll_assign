#pragma once

#include <fstream>
#include <vector>
#include <sstream>

#include "dllist.h"
#include "item.h"

void readFromFile(const char* fileName, List<Item>& list) {
	//create an input stream
	std::ifstream in(fileName);

	//check if file is available or not
	if (in.fail()) {
		std::cout << "Failed to open file!\n";
		return;
	}

	std::string input, token;
	std::vector<std::string> vec;

	//to skip the first line in our file, based
	//on the format provided
	std::getline(in, input);

	while (std::getline(in, input)) {

		//Just to skip an unwanted tab lines or empty lines
		if (input != "" && input != "\t") {
			//a stringStream to put the string buffer data into
			std::istringstream ss(input);
			//using stringStream to tokenize based on tab delimiter
			//vector to hold those tokens
			while (std::getline(ss, token, '\t'))
				vec.push_back(token);

			Item item(atoi(vec[2].c_str()), vec[0], vec[1], vec[3], vec[4]);
			list.addToTail(item);

			//clearing vector of previous data
			vec.clear();
		}
	}

	std::cout << "File loaded!\n";
	in.close();
}

void menu(int &in) {

	std::cout << "1) Load from file into the List\n"
			<< "2) Add at the start of the List\n"
			<< "3) Add at the end of the List\n"
			<< "4) Add before an item in the List\n"
			<< "5) Add after an item in the List\n"
			<< "6) Delete first item in the List\n"
			<< "7) Delete last item in the List\n"
			<< "8) Delete an item with a specific ID from the List\n"
			<< "9) Swap two items in the List\n"
			<< "10) Sort specific portion of the List\n"
			<< "11) Print List\n"
			<< "12) Print List in reverse\n"
			<< "13) EXIT\n";
	
	std::cout << "\n\nPlease enter your choice: ";
	std::cin >> in;
	//checks for valid option
	while (in <= 0 || in > 13) {
		std::cout << "Enter number from 1 to 13: ";
		std::cin >> in;
	}
}

void inputItem(std::vector<std::string>& vec) {

	std::string in;

	std::cout << "Enter ID: ";
	std::getline(std::cin, in);
	vec.push_back(in);
	std::cout << "\n";

	std::cout << "Enter Name: ";
	std::getline(std::cin, in);
	vec.push_back(in);
	std::cout << "\n";

	std::cout << "Enter Price: ";
	std::cin >> in;
	vec.push_back(in);
	std::cout << "\n";

	std::cout << "Enter Category: ";
	std::cin.ignore();
	std::getline(std::cin, in);
	vec.push_back(in);
	std::cout << "\n";

	std::cout << "Enter Company: ";
	std::getline(std::cin, in);
	vec.push_back(in);
}

//for printing purposes
std::string stringPad(std::string str, char ch, int count) {
    	str.resize(count, ch);
    	return str;
}