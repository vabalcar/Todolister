#pragma once
#include <unordered_map>

#include "TOIIO.h"

class TOIIORegister {
public:
	TOIIO& operator[](const string& toiName) const;
	void addTOIIO(const string& name, toiIOPtr toi);
	bool toiIOExists(const string& name) const;
private:
	unordered_map<string, toiIOPtr> registeredTOIIOs_;
};