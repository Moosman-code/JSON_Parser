#pragma once
#include <fstream>
#include <regex>

void Trim(std::string& line) {
	std::string modifiedLine;

	int left = 0;
	while (line[left] == ' ') {
		left++;
	}

	int right = line.size() - 1;
	while (line[right] == ' ') {
		right--;
	}

	line = line.substr(left, right - left + 1);
}

std::vector<std::string> GetPair(std::string& line) {
	std::vector<std::string> pair;

	std::regex rgx("\"(.+)\" *: *([^,]+),*");
	std::smatch match;
	if (std::regex_search(line, match, rgx)) {
		pair.push_back(match[1]);
		pair.push_back(match[2]);
	}

	return pair;
}

bool CheckIfInt(std::string& value) {
	for (char digit : value) {
		if (isdigit(digit) == 0) {
			return false;
		}
	}

	return true;
}

bool CheckIfDouble(std::string& value) {
	size_t position = 0;
	double number = stod(value, &position);

	// Doesnt account for values like 123.123f, 123.123ULL...
	if (position < value.size()) {
		return false;
	}

	return true;
}

