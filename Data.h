#pragma once
#include <iostream>
#include <iomanip>
extern int globalSpacing;

class Data {
public:
	virtual void Print() = 0;
	virtual Data* Clone() = 0;
};

