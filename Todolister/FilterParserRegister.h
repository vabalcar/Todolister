#pragma once
#include <unordered_map>

#include "FilterParser.h"

class FilterParserRegister {
public:
	const FilterParser& operator[](const string& name) const;
	void addParser(const string& name, filterParserPtr parser);
	bool exists(const string& name) const;
	auto begin() const { return registeredParsers_.begin(); }
	auto end() const { return registeredParsers_.end(); }
private:
	unordered_map<string, filterParserPtr> registeredParsers_;
};