//
// Created by Vojtěch Parkán on 15.02.2026.
//

#include "BitcoinExchange.hpp"
#include <sstream>

const std::string whiteSpaces(" \f\n\r\t\v");

void trimRight(std::string & str, const std::string & trimChars = whiteSpaces) {
	std::string::size_type pos = str.find_last_not_of(trimChars);
	str.erase(pos + 1);
}

void trimLeft(std::string & str, const std::string & trimChars = whiteSpaces) {
	std::string::size_type pos = str.find_first_not_of(trimChars);
	str.erase(0, pos);
}

void trim(std::string & str, const std::string & trimChars = whiteSpaces) {
	trimRight(str, trimChars);
	trimLeft(str, trimChars);
}

std::array<std::string, 2> split(const std::string & s, const std::string & delimiter) {
	std::array<std::string, 2> tokens;
	size_t pos = 0;
	std::string token;
	pos = s.find(delimiter);
	token = s.substr(0, pos);
	trim(token, whiteSpaces);
	tokens[0] = token;
	token = s.substr(pos + 1, std::string::npos);
	trim(token, whiteSpaces);
	tokens[1] = token;
	return tokens;
}

void BitcoinExchange::validate_file(std::string data_file, std::string input_file) {
	std::ifstream data(data_file);
	std::ifstream input(input_file);
	if (!data.is_open() || !input.is_open())
		throw(std::string) "cannot open data.csv or input.txt ";
	data.close();
	input.close();
	_data = "data.csv";
	_file = input_file;
}

BitcoinExchange::BitcoinExchange() {
	try {
		validate_file("data.csv", "input.txt");
	} catch (std::string e) {
		std::cerr << e << std::endl;
		exit(1);
	}
}
BitcoinExchange::BitcoinExchange(std::string file) : _file(file) {
	try {
		validate_file("data.csv", file);
	} catch (std::string e) {
		std::cerr << e << std::endl;
		exit(1);
	}
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {
	(void) other;
	//*this = other;
}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & src) {
	if (this != &src) {
		_data = src._data;
		_file = src._file;
		_rates = src._rates;
	}
	return *this;
}

bool validateDate(std::string date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (isdigit(date[i]) == 0)
			return (false);
	}

	if (date[5] == '0' && date[6] == '0')
		return (false);
	if ((date[5] == '1' && date[6] > '2') || date[5] > '1')
		return (false);

	if (date[8] == '0' && date[9] == '0')
		return (false);
	if ((date[8] == '3' && date[9] > '1') || date[8] > '3')
		return (false);

	return (true);
}

void BitcoinExchange::run_filedata() {
	std::ifstream infile(_file);
	std::string line;
	while (std::getline(infile, line) && line.length() != 0)
	{
		if (line == "date | value") {
			continue;
		}
		std::array<std::string, 2> spl;
		double ix;
		std::string date;
		if (line.find('|') != std::string::npos) {
			spl = split(line, "|");
			date = spl[0];
			trim(date, whiteSpaces);
			if (!validateDate(date)) {
				spl[0] = "Error: Wromg Date format " + spl[0];
			}
			std::istringstream iss(spl[1]);
			iss >> ix;
			if (ix > 1000) {
				spl[0] = "Error: too large a number.";
			}
			if (ix < 0) {
				spl[0] = "Error: not a positive number.";
			}
		} else {
			spl[0] = "Error: bad input => " + line;
		}
		if (spl[0].find("Error:") != std::string::npos) {
			std::cout << spl[0] << std::endl;
		} else {
			std::map<std::string, double>::iterator it = _rates.find(date);
			double rate;
			if (it != _rates.end())
				rate = it->second;
			else {
				std::map<std::string, double>::iterator init = _rates.lower_bound(date);
				if (init != _rates.begin())
					init--;
				rate = init->second;
			}
			std::cout << date << " => " << ix << " = " << (ix * rate) << std::endl;
		}
	}
	infile.close();
}

void BitcoinExchange::fill_exchangedata() {
	std::ifstream infile(_data);
	std::string line;
	while (std::getline(infile, line) && line.length() != 0)
	{
		if (line.find("exchange_rate") != std::string::npos) {
			continue;
		}
		std::array<std::string, 2> spl = split(line, ",");
		double ix;
		std::istringstream iss(spl[1]);
		iss >> ix;
		std::string date = spl[0];
		trim(date, whiteSpaces);
		_rates.insert(std::map<std::string, double>::value_type(date, ix));
	}
	infile.close();
}

void BitcoinExchange::parseFile() {
	fill_exchangedata();
//	std::cout << "rates" << std::endl;
//	for (std::map<std::string , double>::const_iterator it = _rates.begin(); it != _rates.end(); it++) {
//		std::cout << it->first << "|" << it->second << std::endl;
//	}
	run_filedata();
}
