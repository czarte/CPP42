//
// Created by Vojtěch Parkán on 15.02.2026.
//

#include "BitcoinExchange.hpp"
#include <sstream>

std::vector<std::string> split(const std::string & s, const std::string & delimiter) {
	std::vector<std::string> tokens;
	size_t pos = 0;
	std::string token;
	pos = s.find(delimiter);
	token = s.substr(0, pos);
	tokens.push_back(token);
	token = s.substr(pos + 1, std::string::npos);
	tokens.push_back(token);
	return tokens;
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream data("data.csv");
	if (!data.is_open())
		throw(std::string) "cannot open data";
}
BitcoinExchange::BitcoinExchange(std::string file) : _file(file) {
	std::cout << "BitcoinExchange constructed" << std::endl;
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {
	*this = other;
}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & src) {
	if (this != &src) {
		this->_dateval = src._dateval;
		this->_file = src._file;
	}
	return *this;
}

void BitcoinExchange::parseFile() {
	std::cout << "parsing file" << std::endl;
	std::ifstream file(_file);
	std::string line;

	while (std::getline(file, line) && line.length() != 0)
	{
		if (line.find("exchange_rate") == 5) {
			std::cout << "found: " << line.find("exchange_rate") << std::endl;
			continue;
		}
		//TODO change this to array
		std::vector<std::string> spl = split(line, ",");
		float ix;
		std::istringstream iss(spl[1]);
		iss >> ix;
		_dateval.insert(std::map<std::string, float>::value_type(spl[0], ix));
	}
	for (std::map<std::string, float>::const_iterator it = _dateval.begin(); it != _dateval.end(); it++) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
}
