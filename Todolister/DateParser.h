#pragma once
#include <string>

#include "Date.h"

using namespace std;

class DateParser {
public:
	virtual datePtr tryParse(const string& s) const = 0;

	virtual ~DateParser() = default;
};