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

std::pair<std::string, std::string> split(const std::string & s, const std::string & delimiter) {
	size_t pos = s.find(delimiter);
	std::string first = s.substr(0, pos);
	trim(first, whiteSpaces);
	std::string second;
	if (pos != std::string::npos)
		second = s.substr(pos + delimiter.size(), std::string::npos);
	trim(second, whiteSpaces);
	return std::make_pair(first, second);
}

void BitcoinExchange::validateFile(const char* data_file, const char* input_file) {
	std::fstream data;
	std::fstream input;
    data.open(data_file, std::fstream::in);
    input.open(input_file, std::fstream::in);
	if (!data.is_open() || !input.is_open()) {
		data.close();
		input.close();
		throw(std::string) "cannot open data.csv or input.txt ";
    }
	_data = "data.csv";
	_file = input_file;
}

BitcoinExchange::BitcoinExchange() {
	try {
		validateFile("data.csv", "input.txt");
	} catch (std::string e) {
		throw e;
	}
}
BitcoinExchange::BitcoinExchange(const char* file) : _file(file) {
	try {
		validateFile("data.csv", file);
	} catch (std::string e) {
		throw e;
	}
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {
	*this = other;
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

	std::set<int> months31;
	months31.insert(1);
	months31.insert(3);
	months31.insert(5);
	months31.insert(7);
	months31.insert(8);
	months31.insert(10);
	months31.insert(12);

	std::set<int> months30;
	months30.insert(4);
	months30.insert(6);
	months30.insert(9);
	months30.insert(11);

	std::set<int> leapYears;
	leapYears.insert(1972);
	leapYears.insert(1976);
	leapYears.insert(1980);
	leapYears.insert(1984);
	leapYears.insert(1988);
	leapYears.insert(1992);
	leapYears.insert(1996);
	leapYears.insert(2000);
	leapYears.insert(2004);
	leapYears.insert(2008);
	leapYears.insert(2012);
	leapYears.insert(2016);
	leapYears.insert(2020);
	leapYears.insert(2024);

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1970 || year > 2026)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1)
		return (false);

	if (months31.find(month) != months31.end()) {
		if (day > 31)
			return (false);
	}
	else if (months30.find(month) != months30.end()) {
		if (day > 30)
			return (false);
	}
	else {
		int maxDay = (leapYears.find(year) != leapYears.end()) ? 29 : 28;
		if (day > maxDay)
			return (false);
	}

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
			std::pair<std::string, std::string> spl = split(line, "|");
			date = spl.first;
			token = spl.second;
			trim(date, whiteSpaces);
            //std::cout << "DEBUG " << date << " | " << token << std::endl;
			if (!validateDate(date)) {
				token = "Error: Wrong Date format " + date;
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
		std::pair<std::string, std::string> spl = split(line, ",");
		std::string date = spl.first;
		std::string token = spl.second;
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
