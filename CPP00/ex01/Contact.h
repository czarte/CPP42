//
// Created by Vojtěch Parkán on 17.01.2025.
//

#ifndef CPP00_CONTACT_H
#define CPP00_CONTACT_H

#include <iostream>

class Contact {
	private:
		int index;
		std::string name;
		std::string surname;
		std::string nickname;
		std::string secret;
		std::string phone;

	public:
		Contact();
		void placeContact(int index, std::string[]);
		~Contact();
		int get_index() const;
		std::string get_name() const;
		std::string get_surname() const;
		std::string get_nickname() const;
		std::string get_phone() const;
		std::string get_secret() const;
};


#endif //CPP00_CONTACT_H
