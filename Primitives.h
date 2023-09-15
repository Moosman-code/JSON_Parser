#pragma once

#include <string>
#include "Data.h"

class String : public Data {
private:
	std::string value;
public:
	// FUNCTIONS
	void Print() override {
		if (this != nullptr) {
			std::cout << "\"" << value << "\"" << std::endl;
		}
	}

	// HELPERS OF BIG 3
	Data* Clone() override {
		return new String(this->value);
	};
	std::string& Get() {
		return this->value;
	}
	void Set(const std::string& _value) {
		this->value = _value;
	}

	// BIG 3
	String() = default;
	String(const std::string& _value) {
		this->Set(_value);
	}
	String(const String& other) {
		this->value = other.value;
	}
	String& operator=(const String& other) {
		if (this != &other) {
			this->value = other.value;
		}

		return *this;
	}
};

class Int : public Data {
private:
	int value;
public:
	// FUNCTIONS
	void Print() override {
		std::cout << value << std::endl;
	}

	// HELPERS OF BIG 3
	Data* Clone() override {
		return new Int(this->value);
	};
	int Get() {
		return this->value;
	}
	void Set(const int _value) {
		this->value = _value;
	}

	// BIG 3
	Int() = default;
	Int(const int _value) {
		this->Set(_value);
	}
	Int& operator=(const Int& other) {
		if (this != &other) {
			this->value = other.value;
		}

		return *this;
	}
};

class Double : public Data {
private:
	double value;
public:
	// FUNCTIONS
	void Print() override {
		std::cout << value << std::endl;
	}

	// HELPERS BIG 3
	Data* Clone() override {
		return new Double(this->value);
	};
	double Get() {
		return this->value;
	}
	void Set(const double _value) {
		this->value = _value;
	}

	// BIG 3
	Double() = default;
	Double(const double _value) {
		this->Set(_value);
	}
	Double& operator=(const Double& other) {
		if (this != &other) {
			this->value = other.value;
		}

		return *this;
	}
};

class Bool : public Data {
private:
	bool value;
public:
	// FUNCTIONS
	void Print() override {
		std::cout << value << std::endl;
	}

	// HELPERS OF BIG 3
	Data* Clone() override {
		return new Bool(this->value);
	};
	bool Get() {
		return this->value;
	}
	void Set(bool _value) {
		this->value = _value;
	}

	// BIG 3
	Bool() = default;
	Bool(bool _value) {
		this->Set(_value);
	}
	Bool& operator=(const Bool& other) {
		if (this != &other) {
			this->value = other.value;
		}

		return *this;
	}
};

class Null : public Data {
private:
	int* value = nullptr;
public:
	// FUNCTIONS
	void Print() override {
		std::cout << "null" << std::endl;
	}
	Data* Clone() override {
		return new Null();
	};

	Null() = default;
};
