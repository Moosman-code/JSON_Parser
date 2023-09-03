// JSONParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Primitives.h"
#include "Vector.h"
#include "JSON.h"

int main()
{
	Data* str = new String("example");
	Double* number = new Double(1.08484f);
	Vector* vector1 = new Vector(std::vector<Data*> {str, number});

	return 0;
}