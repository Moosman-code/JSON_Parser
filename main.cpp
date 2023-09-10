// JSONParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Commands.h"

int main()
{
	std::string str = "123.123";
	std::cout << CheckIfDouble(str);
}