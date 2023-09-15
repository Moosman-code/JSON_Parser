#pragma once

#include "JSON.h"
#include "Vector.h"
#include "Primitives.h"
#include "Utilities.h"

JSON* CreateJSON(std::ifstream& file, std::string& line);
Vector* CreateVector(std::ifstream& file, std::string& line);
Data* CreateValue(std::string& value);

Data* Deserialize(std::ifstream& file) {
	globalSpacing = 0;
	std::string line;
	Data* returnValue = nullptr;
	
	while (getline(file, line)) {
		Trim(line);
		if (line.size() != 0) {
			if (line == "{") {
				returnValue = CreateJSON(file, line);
			}
			else if (line == "[") {
				returnValue = CreateVector(file, line);
			}
			else if (line == "null") {
				std::cout << "JSON file contains only null object" << std::endl;
				returnValue = new Null();
			}
		}
		else if (line.size() == 0) {
			continue;
		}
	}

	return returnValue;
}

JSON* CreateJSON(std::ifstream& file, std::string& line) {
	getline(file, line);
	Trim(line);
	JSON* json = new JSON();

	//  A JSON Object is being created -> only a key-value pair can follow
	while (line != "}") {
		if (line == "") {
			getline(file, line);
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
		getline(file, line);
		Trim(line);
	}
	
	return json;
}


Vector* CreateVector(std::ifstream& file, std::string& line) {
	getline(file, line);
	Trim(line);
	Vector* vector = new Vector();

	while (line != "]") {
		if (line == "") {
			getline(file, line);
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
		getline(file, line);
		Trim(line);
	}

	return vector;
}

Data* CreateValue(std::string& value) {
	Data* returnValue = nullptr;
	if (value == "null") {
		returnValue = new Null();
	}
	else if (value == "[]") {
		returnValue = new Vector();
	}
	else if (value == "{}") {
		returnValue = new JSON();
	}
	else if (value[0] == '\"' && value[value.size() - 1] == '\"') {
		returnValue = new String(value.substr(1, value.size() - 2));
	}
	else if (value == "true") {
		returnValue = new Bool(true);
	}
	else if (value == "false") {
		returnValue = new Bool(false);
	}
	else if (CheckIfInt(value)) {
		returnValue = new Int(stoi(value));
	}
	else if (CheckIfDouble(value)) {
		returnValue = new Double(stod(value));
	}

	return returnValue;
};