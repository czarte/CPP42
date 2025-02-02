//
// Created by Vojtěch Parkán on 17.01.2025.
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "PhoneBook.h"
#include "Contact.h"

PhoneBook::PhoneBook() {
	this->index = 0;
	this->entry = 0;
	this->input = "";
	std::cout << "Welcome to the PhoneBook" << std::endl;
	std::cout << "Use 'help' or 'h' to see the options." << std::endl;
}

PhoneBook::~PhoneBook() {}

int PhoneBook::loop() {
	int exit = 0;

	while (!exit) {
		std::cout << "PhoneBook:";
		std::getline(std::cin, this->input);
		exit = this->resolve_input(this->input);
	}
	return exit;
}

int PhoneBook::resolve_input(const std::string& input) {
	int exit_code = 0;

	if (input == "exit" || input == "e") {
		exit_code = 1;
	} else if (input == "add" || input == "+") {
		this->do_add();
	} else if (input == "search" || input == "s") {
		this->search();
	} else if (input == "help" || input == "h") {
		this->help();
	}
	return exit_code;
}

void PhoneBook::help() {
	PhoneBook::printLine(23, '-');
	std::cout << "Type: " << std::endl << "help' or 'h' for help" << std::endl
		<< "'search' or 's' for search" << std::endl
		<< "'add' or '+' for add new Contact" << std::endl
		<< "'exit' or 'e' for exit the program" << std::endl;
	PhoneBook::printLine(23, '-');
}

void PhoneBook::do_add() {
	std::string details;
	std::string labels[5] = {"number", "nickname", "name", "surname", "secret"};
	std::string inputs[5];
	bool fail = false;

	std::cout << "Insert details" << std::endl;
	for (int i = 0; i <= 4; ++i) {
		std::cout << "Contact " << labels[i] << ": ";
		std::getline(std::cin, inputs[i]);
	}

	for (int i = 0; i <= 4; ++i) {
		if (inputs[i].empty()) {
			std::cout << "Contact field '" << labels[i] << "' cannot be empty."  << std::endl;
			fail = true;
		}
	}
	if (fail) { return; }

	this->add(this->entry, inputs);
}

void PhoneBook::printContact(Contact& contact, bool full) {
	int	index = contact.get_index();
	std::string name = contact.get_name();
	std::string surname = contact.get_surname();
	std::string nickname = contact.get_nickname();

	if (!full) {
		if (name.length() > 10) {
			name = name.substr(0, 9);
			name.append(".");
		}
		if (surname.length() > 10) {
			surname = surname.substr(0, 9);
			surname.append(".");
		}
		if (nickname.length() > 10) {
			nickname = nickname.substr(0, 9);
			nickname.append(".");
		}
	}
	if (full) {
		if (name.empty()) {
			std::cout << "Contact does not exists" << std::endl;
			return;
		}
		std::cout
				<< "index: " << index + 1  << std::endl
				<< "name: " << name  << std::endl
				<< "surname: " << surname  << std::endl
				<< "nickname: " << nickname  << std::endl;
		std::string phone =  contact.get_phone();
		std::string secret = contact.get_secret();
		std::cout
			<< "phone: " << phone << std::endl
			<< "secret: " << secret << std::endl;
	} else {
		std::cout
				<< "| " << index + 1 << std::string(9, ' ')
				<< "| " << name << std::string(10 - name.length(), ' ')
				<< "| " << surname << std::string(10 - surname.length(), ' ')
				<< "| " << nickname << std::string(10 - nickname.length(), ' ')
				<< "|" << std::endl;
	}
}

void PhoneBook::printHeader(bool full) {
	int len = 49;

	if (full) { len = 73; }
	PhoneBook::printLine(len, '_');

	std::cout
			<< "| " << "index" << std::string(5, ' ')
			<< "| " << "name" << std::string(6, ' ')
			<< "| " << "surname" << std::string(3, ' ')
			<< "| " << "nickname" << std::string(2, ' ')
			<< "|" << std::endl;

	PhoneBook::printLine(len, '=');
}

void PhoneBook::printLine(int len, char c) {
	std::cout << std::string(len, c) << std::endl;
}

bool PhoneBook::is_empty_phonebook() {
	int idx = 0;

	for (int i = 0; i < 7; ++i) {
		if (this->contacts[i].get_name().empty())
			break;
		idx++;
	}

	if (idx == 0) {
		PhoneBook::printLine(23, '-');
		std::cout << "No entry yet" << std::endl;
		PhoneBook::printLine(23, '-');
		return true;
	}
	return false;
}

void PhoneBook::search() {
	int idx = 0;

	if (is_empty_phonebook())
		return;
	PhoneBook::printHeader();
	for(int i = 0; i < this->index; i++) {
		printContact(this->contacts[i]);
		printLine(49, '-');
	}
	std::string str;
	std::cout << "Insert index of contact you want to display:" << std::endl;
	std::getline(std::cin, str);
	std::istringstream iss(str);
	iss >> idx;
	if (idx == 0) {
		std::cout << "Contact index must be only digit from 0 up to 8." << std::endl;
		return;
	}
	std::cout << "Contact " << idx << std::endl;
	if (idx >= 1 && idx <= 8) {
		PhoneBook::printLine(23, '-');
		printContact(this->contacts[idx - 1], true);
		PhoneBook::printLine(23, '-');
		return;
	} else {
		std::cout << "insert index from 0 up to 8. Only 8 objects could be stored" << this->input << std::endl;
		return;
	}
}

int PhoneBook::add(int u, std::string details[]) {
	if (this->index < 8) {
		this->index++;
	}
	this->contacts[this->entry].placeContact(u, details);
	if (this->entry < 7) {
		this->entry++;
	} else {
		this->entry = 0;
	}
	return 0;
}
