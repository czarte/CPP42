//
// Created by Vojtěch Parkán on 15.02.2026.
//

#ifndef CPP42_BITCOINEXCHANGE_HPP
#define CPP42_BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <stack>

class BitcoinExchange {
private:
	const char* _file;
	const char* _data;
	std::map<std::string, double> _rates;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const char* file);
	BitcoinExchange(const BitcoinExchange & other);
	BitcoinExchange& operator=(const BitcoinExchange & src);

	void validateFile(const char* data_file, const char* input_file);
	void runFiledata();
	void fillExchangedata();
	void parseFile();
};


#endif //CPP42_BITCOINEXCHANGE_HPP
