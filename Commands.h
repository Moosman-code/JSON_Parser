#pragma once

#include "JSON.h"
#include "Vector.h"
#include "Primitives.h"
#include "Utilities.h"

JSON* CreateJSON(std::ifstream& file, std::string& line);
Vector* CreateVector(std::ifstream& file, std::string& line);

JSON* Deserialize(std::ifstream& file) {
	std::string line;

	while (file >> line) {
		Trim(line);

		if (line.size() == 1) {
			if (line == "{") {
				JSON* json = CreateJSON(file, line);
			}
			else if (line == "[") {
				Vector* vector = CreateVector(file, line);
			}
		}
		else if (line.size() == 0) {
			continue;
		}
		else {

		}
	}

	return nullptr;
}
JSON* CreateJSON(std::ifstream& file, std::string& line) {
	file >> line;
	Trim(line);
	JSON* json = new JSON();

	//  A JSON Object is being created -> only a key-value pair can follow
	while (line != "}") {
		std::vector<std::string> pair = GetPair(line);

		file >> line;
	}
	
	return json;
}


Vector* CreateVector(std::ifstream& file, std::string& line) {
	return nullptr;
}