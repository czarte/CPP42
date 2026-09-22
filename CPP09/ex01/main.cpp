#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
		return (1);
	}
	try
	{
		RPN rpn(argv[1]);
		std::cout << rpn.get_result() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
