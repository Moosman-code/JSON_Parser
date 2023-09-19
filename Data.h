#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
extern int globalSpacing;

class Data {
public:
	virtual Data* Clone() = 0;
	virtual void Print() = 0;
	virtual void Search(std::string& key, std::vector<Data*>& vector) = 0;
	virtual bool Set(std::queue<std::string>& path, Data* replaceValue) = 0;
	virtual bool Find(std::queue<std::string>& path) = 0;
};

