// JSONParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Commands.h"

int main()
{
	std::string line =  "  \"randomKey\": value,    ";
	Trim(line);
	std::cout << line;

	return 0;
}