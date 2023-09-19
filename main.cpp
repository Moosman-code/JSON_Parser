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

	//Delete
	/*std::string path = "company/employees";
	std::queue<std::string> queue;
	FillQueue(queue, path);
	if (result->Find(queue)) {
		std::cout << result->Delete(queue);
		result->Print();
	}*/

	//Create
	/*std::string path = "company/employees/2/worktime/season";
	Data* flag = new String("Summer");
	std::queue<std::string> queue;
	FillQueue(queue, path);
	if (!result->Find(queue)) {
		result->Create(queue, flag);
	}
	else {
		std::cout << "Value already exists" << std::endl;
	}

	result->Print();*/

	// Find
	/*std::string path = "company/employees/projects/endDate";
	std::queue<std::string> queue;
	FillQueue(queue, path);
	bool flag = result->Find(queue);
	std::cout << flag;*/

	// Set (Works only with primitives, so far)
	/*std::queue<std::string> queue;
	std::string path;
	std::getline(std::cin, path);

	std::string input;
	std::getline(std::cin, input);
	Data* replaceValue = CreateValue(input);
	Data* str = new String("The Manhatan Project");

	FillQueue(queue, path);

	bool flag = result->Set(queue, str);
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