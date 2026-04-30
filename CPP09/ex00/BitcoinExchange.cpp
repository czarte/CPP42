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

std::stack<std::string> split(const std::string & s, const std::string & delimiter) {
	std::stack<std::string> tokens;
	size_t pos = 0;
	std::string token;
	pos = s.find(delimiter);
	token = s.substr(0, pos);
	trim(token, whiteSpaces);
	tokens.push(token);
	token = s.substr(pos + 1, std::string::npos);
	trim(token, whiteSpaces);
	tokens.push(token);
	return tokens;
}

void BitcoinExchange::validateFile(const char* data_file, const char* input_file) {
	std::fstream data;
	std::fstream input;
    data.open(data_file, std::fstream::in);
    input.open(input_file, std::fstream::in);
	if (!data.is_open() || !input.is_open())
		throw(std::string) "cannot open data.csv or input.txt ";
	data.close();
	input.close();
	_data = "data.csv";
	_file = input_file;
}

BitcoinExchange::BitcoinExchange() {
	try {
		validateFile("data.csv", "input.txt");
	} catch (std::string e) {
		std::cerr << e << std::endl;
		exit(1);
	}
}
BitcoinExchange::BitcoinExchange(const char* file) : _file(file) {
	try {
		validateFile("data.csv", file);
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

void BitcoinExchange::runFiledata() {
	std::fstream infile;
    infile.open(_file, std::fstream::in);
	std::string line;
	while (std::getline(infile, line) && line.length() != 0)
	{
		if (line == "date | value") {
			continue;
		}
		double ix;
		std::string date;
		std::string token;
		if (line.find('|') != std::string::npos) {
			std::stack<std::string> spl = split(line, "|");
			token = spl.top();
            spl.pop();
            date = spl.top();
			trim(date, whiteSpaces);
            //std::cout << "DEBUG " << date << " | " << token << std::endl;
			if (!validateDate(date)) {
				date = "Error: Wromg Date format " + date;
			}
			std::istringstream iss(token);
			iss >> ix;
			if (ix > 1000) {
				token = "Error: too large a number.";
			}
			if (ix < 0) {
				token = "Error: not a positive number.";
			}
		} else {
			token = "Error: bad input => " + line;
		}
		if (token.find("Error:") != std::string::npos) {
			std::cout << token << std::endl;
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

void BitcoinExchange::fillExchangedata() {
	std::ifstream infile(_data);
	std::string line;
	while (std::getline(infile, line) && line.length() != 0)
	{
		if (line.find("exchange_rate") != std::string::npos) {
			continue;
		}
		std::stack<std::string> spl = split(line, ",");
        std::string token = spl.top();
        spl.pop();
        std::string date = spl.top();
		double ix;
		std::istringstream iss(token);
        //std::cout << "DEBUG RATE " << date << " | " << token << std::endl;
		iss >> ix;
		_rates.insert(std::map<std::string, double>::value_type(date, ix));
	}
	infile.close();
}

void BitcoinExchange::parseFile() {
	fillExchangedata();
	runFiledata();
}
