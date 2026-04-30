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

class BitcoinExchange {
private:
	std::string _file;
	std::string _data;
	std::map<std::string, double> _rates;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(std::string file);
	BitcoinExchange(const BitcoinExchange & other);
	BitcoinExchange& operator=(const BitcoinExchange & src);

	void validate_file(std::string data_file, std::string input_file);
	void run_filedata();
	void fill_exchangedata();
	void parseFile();

};


#endif //CPP42_BITCOINEXCHANGE_HPP
