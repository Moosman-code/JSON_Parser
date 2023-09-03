#pragma once
#include <iostream>


class Data {
public:
	virtual void Print() = 0;
	virtual Data* Clone() = 0;
};

