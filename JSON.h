#pragma once

#include <unordered_map>
#include "Data.h"

class JSON : public Data {
private:
	std::unordered_map<std::string, Data*> dictionary;
public:
	// FUNCTIONS
	void Print() {
		for (const auto& pair : this->dictionary) {
			std::cout << pair.first << ":\n";
			pair.second->Print();
			std::cout << std::endl;
		}
	}

	// HELPERS OF BIG 4
	std::unordered_map<std::string, Data*>& Get() {
		return this->dictionary;
	}
	void Set(const std::unordered_map<std::string, Data*>& otherDictionary) {
		for (const auto& pair : otherDictionary) {
			this->dictionary.insert(std::pair<std::string, Data*>(pair.first, pair.second->Clone()));
		}
	}
	Data* Clone() {
		std::unordered_map<std::string, Data*> newDictionary;
		for (const auto& pair : this->dictionary) {
			newDictionary.insert(std::pair<std::string, Data*>(pair.first, pair.second->Clone()));
		}

		return new JSON(newDictionary);
	}
	void Clear() {
		for (const auto& pair : this->dictionary) {
			delete pair.second;
		}
	}

	// BIG 4
	JSON() = default;
	JSON(std::unordered_map<std::string, Data*>& otherDictionary) {
		this->Set(otherDictionary);
	}
	JSON(const JSON& other) {
		this->Set(other.dictionary);
	}
	~JSON() {
		this->Clear();
	}
	JSON& operator=(const JSON& other) {
		if (this != &other) {
			this->Clear();
			this->Set(other.dictionary);
		}

		return *this;
	}
};



