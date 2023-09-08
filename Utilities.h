#pragma once
#include <fstream>

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

	// Get the key
	pair.push_back(line.substr(1, line.size() - 2));

	return pair;
}

