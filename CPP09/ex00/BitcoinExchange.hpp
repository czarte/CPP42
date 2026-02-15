//
// Created by Vojtěch Parkán on 15.02.2026.
//

#ifndef CPP42_BITCOINEXCHANGE_HPP
#define CPP42_BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>

class BitcoinExchange {
private:
	std::string _file;
	std::map<std::string, float> _dateval;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(std::string file);
	BitcoinExchange(const BitcoinExchange & other);
	BitcoinExchange& operator=(const BitcoinExchange & src);

	void parseFile();
};


#endif //CPP42_BITCOINEXCHANGE_HPP
