#pragma once

#include <unordered_map>
#include "Data.h"

class JSON : public Data {
private:
	std::unordered_map<std::string, Data*> dictionary;
public:
	// FUNCTIONS	
	void Print() { 
		if (this == nullptr) {
			return;
		}

		int localSpacing = globalSpacing;
		globalSpacing += 2;

		std::cout << "{" << std::endl;
		for (const auto& pair : this->dictionary) {
			std::cout << std::setw(localSpacing + 2) << "\"" << pair.first << "\": ";
			pair.second->Print();
		}

		std::cout << std::setw(localSpacing) << "}" << std::endl;
		globalSpacing -= 2;
	}
	void Add(std::string key, Data* value) {
		this->dictionary.insert(std::pair<std::string, Data*>(key, value->Clone()));
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
		return new JSON(this->dictionary);
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



