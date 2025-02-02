//
// Created by Vojtěch Parkán on 02.02.2025.
//

#include "Harl.h"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string level) {
	void (Harl::*complain[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[4] = {"debug", "info", "warning", "error"};

	int i = 0;
	while (levels[i] != level) {
		i++;
	}
	if (i < 4)
		(this->*complain[i])();
	else
		std::cout << "nothign to log";
}

void Harl::debug() {
	std::cout << "DEBUG: I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void Harl::info() {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put"
		<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void Harl::warning() {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for"
		<< "years whereas you started working here since last month."
		<< std::endl;
}

void Harl::error() {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}
