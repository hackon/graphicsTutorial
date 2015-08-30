#include "Errors.h"
#include <iostream>

void fatalError(std::string errorString) {
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit";
	char tmp;
	std::cin >> tmp;
	exit(1);
}