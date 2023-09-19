#pragma once

#include <vector>
#include "Data.h"

class Vector : public Data {
private:
	std::vector<Data*> vector;
public:
	// FUNCTIONS
	void Print() override {
		if (this == nullptr) {
			return;
		}

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
	void Search(std::string& key, std::vector<Data*>& vector) override {
		for (Data* value : this->vector) {
			value->Search(key, vector);
		}
	}
	bool Set(std::queue<std::string>& path, Data* replaceValue) override {
		bool flag = false;

		for (Data* element : this->vector) {
			flag = element->Set(path, replaceValue);
			if (flag == true) {
				return true;
			}
		}

		return false;
	}
	bool Find(std::queue<std::string>& path) override {
		bool flag = false;

		for (Data* value : this->vector) {
			flag = value->Find(path);
			if (flag == true) {
				return true;
			}
		}

		return false;
	}
	

	// HELPERS OF BIG 4
	void Add(Data* value) {
		this->vector.push_back(value->Clone());
	}
	std::vector<Data*>& Get() {
		return this->vector;
	}
	void SetVector(const std::vector<Data*>& _vector) {
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
		this->SetVector(_vector);
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

