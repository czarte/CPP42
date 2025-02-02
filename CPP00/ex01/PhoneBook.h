//
// Created by Vojtěch Parkán on 17.01.2025.
//

#ifndef CPP00_PHONEBOOK_H
#define CPP00_PHONEBOOK_H

#include <iostream>
#include "Contact.h"

class PhoneBook {
private:
	Contact contacts[8];
	int 	index;
	int		entry;
	std::string input;
	static void printContact(Contact& contacts, bool full = false);

public:
	PhoneBook();
	~PhoneBook();
	int loop();
	int resolve_input(const std::string& input);
	int add(int u, std::string details[]);
	void search();
	void do_add();
	void help();
	static void printHeader(bool full = false);
	static void printLine(int len, char c);

	bool is_empty_phonebook();
};


#endif //CPP00_PHONEBOOK_H
