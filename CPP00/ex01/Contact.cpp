//
// Created by Vojtěch Parkán on 17.01.2025.
//

#include <string>
#include "Contact.h"

Contact::Contact(){
	this->index = 0;
}

Contact::~Contact(){}

int Contact::get_index() const {
	return index;
}

std::string Contact::get_name() const {
	return name;
}

std::string Contact::get_surname() const {
	return surname;
}

std::string Contact::get_nickname() const {
	return nickname;
}

std::string Contact::get_phone() const {
	return phone;
}

std::string Contact::get_secret() const {
	return secret;
}

void Contact::placeContact(int u, std::string details[]) {
	this->index = u;
	this->phone = details[0];
	this->nickname = details[1];
	this->name = details[2];
	this->surname = details[3];
	this->secret = details[4];
}
