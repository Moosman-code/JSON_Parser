#pragma once

#include <unordered_map>
#include "Data.h"

class JSON : public Data {
private:
	std::unordered_map<std::string, Data*> dictionary;
public:
	// FUNCTIONS	
	void Print() override { 
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
	void Search(std::string& key, std::vector<Data*>& vector) override{
		for (const auto& pair : this->dictionary) {
			if (pair.first == key) {
				vector.push_back(pair.second->Clone());
			}

			pair.second->Search(key, vector);
		}
	}
	bool Set(std::queue<std::string>& path, Data* replaceValue) override {
		for (auto& pair : this->dictionary) {
			if (pair.first == path.front()) {
				if (path.size() == 1) {
					// Is this necessery
					pair.second = replaceValue->Clone();
					delete replaceValue;
					return true;
				}

				path.pop();
				return pair.second->Set(path, replaceValue);
			}
		}
	}
	bool Find(std::queue<std::string> path) override {
		for (auto& pair : this->dictionary) {
			if (pair.first == path.front()) {
				if (path.size() == 1) {
					return true;
				}

				path.pop();
				return pair.second->Find(path);
			}
		}

		return false;
	}
	bool Create(std::queue<std::string>& path, Data* createValue) override {
		std::string currLevel = path.front();

		for (const auto& pair : this->dictionary) {
			if (pair.first == currLevel) {
				path.pop();
				return pair.second->Create(path, createValue);
			}
		}

		if (path.size() == 1) {
			this->Add(currLevel, createValue);
			return true;
		}
		else {
			this->Add(currLevel, new JSON());
			path.pop();
			return this->dictionary[currLevel]->Create(path, createValue);
		}
	}

	// HELPERS OF BIG 4
	void Add(std::string key, Data* value) {
		this->dictionary.insert(std::pair<std::string, Data*>(key, value->Clone()));
	}
	std::unordered_map<std::string, Data*>& Get() {
		return this->dictionary;
	}
	void SetJSON(const std::unordered_map<std::string, Data*>& otherDictionary) {
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
		this->SetJSON(otherDictionary);
	}
	JSON(const JSON& other) {
		this->SetJSON(other.dictionary);
	}
	~JSON() {
		this->Clear();
	}
	JSON& operator=(const JSON& other) {
		if (this != &other) {
			this->Clear();
			this->SetJSON(other.dictionary);
		}

		return *this;
	}
};



