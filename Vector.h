#pragma once

#include <vector>
#include "Data.h"

class Vector : public Data {
private:
	std::vector<Data*> vector;
public:
	// FUNCTIONS
	void Print() override {
		int localSpacing = globalSpacing;
		globalSpacing += 2;

		std::cout << "[" << std::endl;
		for (Data* value : this->vector) {
			std::cout << std::setw(localSpacing + 2);
			value->Print();
		}

		std::cout<< std::setw(localSpacing) << "]" << std::endl;
		globalSpacing -= 2;
	}
	void Add(Data* value) {
		this->vector.push_back(value->Clone());
	}

	// HELPERS OF BIG 4
	std::vector<Data*>& Get() {
		return this->vector;
	}
	void Set(const std::vector<Data*>& _vector) {
		for (Data* value : _vector) {
			this->vector.push_back(value->Clone());
		}
	}
	Data* Clone() override {
		std::vector<Data*> newVector;
		for (Data* value : this->vector) {
			newVector.push_back(value->Clone());
		}
		return new Vector(newVector);
	}
	void Clear() {
		for (Data* value : this->vector) {
			delete value;
		}
	}

	// BIG 4
	Vector() = default;
	Vector(const std::vector<Data*>& _vector) {
		this->Set(_vector);
	}
	Vector(const Vector& _vector) {
		for (Data* value : _vector.vector) {
			this->vector.push_back(value->Clone());
		}
	}
	~Vector() {
		this->Clear();
	}
	Vector& operator=(const Vector& other) {
		if (this != &other) {
			this->Clear();
			for (Data* value : other.vector) {
				this->vector.push_back(value->Clone());
			}
		}

		return *this;
	}
};

