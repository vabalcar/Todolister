#pragma once
#include <unordered_map>

#include "Format.h"

class FormatRegister {
public:
	FormatRegister() {}
	Format& operator[](const string& formatName) const;
	void addFormat(const string& name, formatPtr format);
	bool formatExists(const string& name) const;
	auto begin() const { return registeredFormats_.begin(); }
	auto end() const { return registeredFormats_.end(); }
private:
	unordered_map<string, formatPtr> registeredFormats_;
};