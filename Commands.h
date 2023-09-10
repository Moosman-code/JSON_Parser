#pragma once

#include "JSON.h"
#include "Vector.h"
#include "Primitives.h"
#include "Utilities.h"

JSON* CreateJSON(std::ifstream& file, std::string& line);
Vector* CreateVector(std::ifstream& file, std::string& line);
Data* CreateValue(std::string& value);

Data* Deserialize(std::ifstream& file) {
	std::string line;
	Data* returnValue = nullptr;

	while (file >> line) {
		Trim(line);

		if (line.size() == 1) {
			if (line == "{") {
				returnValue = CreateJSON(file, line);
			}
			else if (line == "[") {
				returnValue = CreateVector(file, line);
			}
		}
		else if (line.size() == 0) {
			continue;
		}
	}

	return returnValue;
}
JSON* CreateJSON(std::ifstream& file, std::string& line) {
	file >> line;
	Trim(line);
	JSON* json = new JSON();

	//  A JSON Object is being created -> only a key-value pair can follow
	while (line != "}") {
		if (line == "") {
			file >> line;
			continue;
		}

		std::vector<std::string> pair = GetPair(line);
		std::string key = pair[0];
		Data* value = nullptr;
		if (pair[1] == "{") {
			value = CreateJSON(file, line);
		}
		else if (pair[1] == "[") {
			value = CreateVector(file, line);
		}
		else {
			value = CreateValue(pair[1]);
		}
	
		json->Add(key, value);
		file >> line;
	}
	
	return json;
}


Vector* CreateVector(std::ifstream& file, std::string& line) {
	file >> line;
	Trim(line);
	Vector* vector = new Vector();

	while (line != "]") {
		if (line == "") {
			file >> line;
			continue;
		}

		Data* value = nullptr;
		if (line == "{") {
			value = CreateJSON(file, line);
		}
		else if (line == "[") {
			value = CreateVector(file, line);
		}
		else {
			value = CreateValue(line);
		}

		vector->Add(value);
		file >> line;
	}

	return vector;
}

Data* CreateValue(std::string& value) {
	Data* returnValue = nullptr;

	if (value[0] == '\"' && value[value.size() - 1] == '\"') {
		returnValue = new String(value.substr(1, value.size() - 2));
	}
	else if (value == "true") {
		returnValue = new Bool(true);
	}
	else if (value == "false") {
		returnValue = new Bool(false);
	}
	else if (CheckIfInt(value)) {
		returnValue == new Int(stoi(value));
	}
	else if (CheckIfDouble(value)) {
		returnValue = new Double(stod(value));
	}

	return returnValue;
}