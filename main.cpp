// JSONParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Deserialize.h"

int globalSpacing = 0;

int main()
{
	std::ifstream file;
	file.open("example.json");
	Data* result = Deserialize(file);

	// Search
	Vector* vector = new Vector();
	std::string key = "name";
	result->Search(key, vector->Get());
	if (vector->Get().size() != 0) {
		vector->Print();
	}
	else {
		std::cout << "No results found" << std::endl;
	}
}