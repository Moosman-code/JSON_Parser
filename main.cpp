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

	// Find
	std::string path = "company/employees/projects/startDate1";
	std::queue<std::string> queue;
	FillQueue(queue, path);
	bool flag = result->Find(queue);
	std::cout << flag;

	// Set (Works only with primitives, so far)
	/*std::queue<std::string> queue;
	std::string path;
	std::getline(std::cin, path);

	std::string input;
	std::getline(std::cin, input);
	Data* replaceValue = CreateValue(input);

	FillQueue(queue, path);

	bool flag = result->Set(queue, replaceValue);
	if (!flag) {
		std::cout << "Invalid path" << std::endl;
	}
	else {
		std::cout << "Value changed" << std::endl;
	}
	result->Print();*/


	// Search
	/*Vector* vector = new Vector();
	std::string key = "name";
	result->Search(key, vector->Get());
	if (vector->Get().size() != 0) {
		vector->Print();
	}
	else {
		std::cout << "No results found" << std::endl;
	}*/
}