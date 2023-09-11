// JSONParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Deserialize.h"

int main()
{
	std::ifstream file;
	file.open("example.json");
	Data* result = Deserialize(file);
	result->Print();
}