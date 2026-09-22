#include "BitcoinExchange.hpp"

int main(int argc, char**argv) {
	if (argc != 2)
		return 0;
	BitcoinExchange btc(argv[1]);
	btc.parseFile();

	return 0;
}
