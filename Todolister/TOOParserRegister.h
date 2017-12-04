#pragma once
#include <unordered_map>

#include "TOOParser.h"

class TOOParserRegister {
public:
	const TOOParser& operator[](const string& name) const;
	void addParser(const string& name, tooParserPtr parser);
	bool exists(const string& name) const;
	auto begin() const { return registeredParsers_.begin(); }
	auto end() const { return registeredParsers_.end(); }
private:
	unordered_map<string, tooParserPtr> registeredParsers_;
};