#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include "Utilities.h"
extern int globalSpacing;

class Data {
public:
	virtual Data* Clone() = 0;
	virtual void Print() = 0;
	virtual void Search(std::string& key, std::vector<Data*>& vector) = 0;
	virtual bool Set(std::queue<std::string>& path, Data* replaceValue) = 0;
	virtual bool Find(std::queue<std::string> path) = 0;
	virtual bool Create(std::queue<std::string>& path, Data* replaceValue) = 0;
	virtual bool Delete(std::queue<std::string>& path) = 0;
};

