#include "BitcoinExchange.hpp"

int main(int argc, char**argv) {
	if (argc != 2)
		return 0;
    try {
    	BitcoinExchange btc(argv[1]);
    	btc.parseFile();
    } catch (std::string e) {
      	std::cerr << e << std::endl;
    }
	return 0;
}
