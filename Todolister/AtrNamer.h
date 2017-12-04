#pragma once
#include <unordered_map>

using namespace std;

class AtrNamer {
public:
	const string& operator[](char c) const;
	const string& getAtrName(char c) const;
	void registerName(char c, string name);
	bool nameExists(char c) const;
	const char getID(const string& name) const;
private:
	unordered_map<char, string> names_;
};