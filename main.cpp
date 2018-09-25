#include "iterator.h"
#include "rev_iterator.h"
#include "util.h"

int main() {

	//created a list object
	List<Item> list;

	int in;
	//to break the loop
	bool check = true;
	while (check) {
		//in util.h
		menu(in);
		
		//just to keep console clean
		//preprocessor directive to check for OS, because I made this on Linux
		#ifdef _WIN32
			system("CLS");
		#else
			system("clear");
		#endif

		//to prevent any code from running other than exit and
		//load file
		if (in != 1 && in != 2 && in != 3 && in != 13 && list.isEmpty()) {
			std::cout << "\n\nList is Empty!\n\n";
			continue;
		}
		std::cout << "\n\n";

		//switch are faster than if/else in this case since compiler
		//can optimize the code using jump-tables etc
		switch (in) {
			case 1: {
				std::string file;
				std::cout << "Enter files name: ";
				//ignore is used between extraction operator and getline
				//to correctly read file name
				std::cin.ignore();
				std::getline(std::cin, file);
				//to append .txt if user doesn't put it in the name
				if (file.find(".txt") == std::string::npos)
					file += std::string(".txt");
				//in util.h
				readFromFile(file.c_str(), list);
				std::cout << "\n";
				break;
			}
			case 2: {
				std::vector<std::string> vec;
				std::cin.ignore();
				//in util.h
				inputItem(vec);
				//create Item object
				Item item(atoi(vec[2].c_str()), vec[0], vec[1], vec[3], vec[4]);
				list.addToHead(item);
				std::cout << "Item added at the start of the List!\n\n";
				break;
			}
			case 3: {
				std::vector<std::string> vec;
				std::cin.ignore();
				//in util.h
				inputItem(vec);
				Item item(atoi(vec[2].c_str()), vec[0], vec[1], vec[3], vec[4]);
				list.addToTail(item);
				std::cout << "Item added at the end of the List!\n\n";
				break;
			}
			case 4: {
				std::cout << "Enter ID of the item to find: ";
				std::string id;
				std::cin.ignore();
				std::getline(std::cin, id);
				//a "dummy" object to find a particular ID
				Item item1(0, id, "", "", "");
				//creates a forward iterator with the node returned by find()
				List<Item>::Iterator it(list.find(item1));
				//checks if iterator does not have a null node
				if (!it.isNull()) {
					std::vector<std::string> vec;
					//in util.h
					inputItem(vec);
					Item item(atoi(vec[2].c_str()), vec[0], vec[1], vec[3], vec[4]);
					list.insertBefore(it, item);
					std::cout << "Item added!\n";
				}
				std::cout << "\n";
				break;
			}
			case 5: {
				std::cout << "Enter ID of the item to find: ";
				std::string id;
				std::cin.ignore();
				std::getline(std::cin, id);
				Item item1(0, id, "", "", "");
				List<Item>::Iterator it(list.find(item1));
				if (!it.isNull()) {
					std::vector<std::string> vec;
					//in util.h
					inputItem(vec);
					Item item(atoi(vec[2].c_str()), vec[0], vec[1], vec[3], vec[4]);
					list.insertAfter(it, item);
					std::cout << "Item added!\n";
				}
				std::cout << "\n";
				break;
			}
			case 6: {
				list.deleteFromHead();
				std::cout << "\n";
				break;
			}
			case 7: {
				list.deleteFromTail();
				std::cout << "\n";
				break;
			}
			case 8: {
				std::cout << "Enter ID of the item to find: ";
				std::string id;
				std::cin.ignore();
				std::getline(std::cin, id);
				Item item1(0, id, "", "", "");
				List<Item>::Iterator it(list.find(item1));
				if (!it.isNull()) {
					list.deleteElement(it);
				}
				std::cout << "\n";
				break;
			}
			case 9: {
				std::cout << "Enter IDs of two items to swap: ";
				std::string id1, id2;
				std::cin.ignore();
				std::getline(std::cin, id1);
				std::getline(std::cin, id2);
				Item item1(0, id1, "", "", "");
				List<Item>::Iterator it1(list.find(item1));
				if (!it1.isNull()) {
					Item item2(0, id2, "", "", "");
					List<Item>::Iterator it2(list.find(item2));
					if(!it2.isNull()) {
						list.swapElements(it1, it2);
						std::cout << "Items swapped!\n";
					}
				}
				std::cout << "\n";
				break;
			}
			case 10: {
				std::cout << "Enter IDs of items to sort list between: ";
				std::string id1, id2;
				std::cin.ignore();
				std::getline(std::cin, id1);
				std::getline(std::cin, id2);
				Item item1(0, id1, "", "", "");
				List<Item>::Iterator it1(list.find(item1));
				if (!it1.isNull()) {
					Item item2(0, id2, "", "", "");
					List<Item>::Iterator it2(list.find(item2));
					if (!it2.isNull()) {
						list.sortList(it1, it2);
						std::cout << "List sorted\n";
					}
				}
				std::cout << "\n";
				break;
			}
			case 11: {
				std::cout << stringPad("", '\t', 5) << "Printing..." << "\n"; 
				std::cout << stringPad("", '~', 38) << stringPad("Start of List", '~', 51) << "\n";
				std::cout << "ID\t\t" << "Name\t\t\t" << "Price\t\t" << "Category\t\t" << "Company\n\n";
				List<Item>::Iterator it1 = list.begin();
				List<Item>::Iterator it2 = list.end();
				++it2;

				for (List<Item>::Iterator i = it1; i != it2; ++i) {
					std::cout << *i;
					std::cout << "\n";
				}
				std::cout << stringPad("", '~', 38) << stringPad("End of List", '~', 51) << "\n\n";		
				break;
			}
			case 12: {
				std::cout << stringPad("", '\t', 4) << "Printing in reverse..." << "\n"; 
				std::cout << stringPad("", '~', 38) << stringPad("Start of List", '~', 51) << "\n";
				std::cout << "ID\t\t" << "Name\t\t\t" << "Price\t\t" << "Category\t\t" << "Company\n\n";
				List<Item>::Rev_Iterator it1 = list.rBegin();
				List<Item>::Rev_Iterator it2 = list.rEnd();
				++it2;

				for (List<Item>::Rev_Iterator i = it1; i != it2; ++i) {
					std::cout << *i;
					std::cout << "\n";
				}
				std::cout << stringPad("", '~', 38) << stringPad("End of List", '~', 51) << "\n\n";
				break;
			}
			case 13: {
				check = false;
				break;
			}
			default: {
				std::cout << "\nWrong Input!\n\n";
				break;
			}
		}
	}

	std::cout << "Thank you for using the program!\n\n";

	std::cin.get(); //used for visual studio 2017
	return 0;
}