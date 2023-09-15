#pragma once
#include <iostream>
#include <iomanip>
extern int globalSpacing;

class Data {
public:
	virtual Data* Clone() = 0;
	virtual void Print() = 0;
	virtual void Search(std::string& key, std::vector<Data*>& vector) = 0;
};

