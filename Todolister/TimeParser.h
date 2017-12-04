#pragma once
#include <string>

#include "Time.h"

class TimeParser {
public:
	virtual timePtr tryParse(const string& source) const = 0;

	virtual ~TimeParser() = default;
};