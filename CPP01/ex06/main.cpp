
#include "Harl.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "HarlFilter need to be run with log level filter \"DEBUG\", \"INFO\", \"WARNING\" or \"ERROR\"'" << std::endl;
		return (0);
	}
	std::string filter = argv[1];
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	bool flag_not = true;
	while (i < 4) {
		if (levels[i] == filter) {
			flag_not = false;
			break;
		}
		i++;
	}
	Harl harl;
	if (flag_not)
		i = 4;
	switch (i) {
		case 0:
			std::cout << "[DEBUG]" << std::endl;
			harl.complain("debug");
			std::cout << std::endl << "[INFO]" << std::endl;
			harl.complain("info");
			std::cout << std::endl << "[WARNING]" << std::endl;
			harl.complain("warning");
			std::cout << std::endl << "[ERROR]" << std::endl;
			harl.complain("error");
			break;
		case 1:
			std::cout << "[INFO]" << std::endl;
			harl.complain("info");
			std::cout << std::endl << "[WARNING]" << std::endl;
			harl.complain("warning");
			std::cout << std::endl << "[ERROR]" << std::endl;
			harl.complain("error");
			break;
		case 2:
			std::cout << "[WARNING]" << std::endl;
			harl.complain("warning");
			std::cout  << std::endl << "[ERROR]" << std::endl;
			harl.complain("error");
			break;
		case 3:
			std::cout << "[ERROR]" << std::endl;
			harl.complain("error");
			break;
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

	return (0);
}
