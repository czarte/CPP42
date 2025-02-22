//
// Created by Vojtěch Parkán on 02.02.2025.
//

#ifndef CPP42_HARL_H
#define CPP42_HARL_H

#include <iostream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl();
		~Harl();
		void complain(std::string);
};


#endif //CPP42_HARL_H
