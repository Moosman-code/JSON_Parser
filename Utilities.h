#pragma once
#include <fstream>
#include <regex>

void Trim(std::string& line) {
	if (line == "") {
		return;
	}

	int left = 0;
	while (line[left] == ' ' || line[left] == '\t') {
		left++;
	}

	int right = line.size() - 1;
	while (line[right] == ' ' || line[right] == '\t') {
		right--;
	}

	line = line.substr(left, right - left + 1);
	if (line[line.size() - 1] == ',') {
		line = line.substr(0, line.size() - 1);	
	}
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

void FillQueue(std::queue<std::string>& path, std::string input) {
	int begin = 0;
	int end = 0;
	std::string location;

	while (begin < input.size()) {
		while ((end + begin) < input.size() && input[end + begin] != '/') {
			end++;
		}

		location = input.substr(begin, end);
		path.push(location);
		begin += end + 1;
		end = 0;
	}
}