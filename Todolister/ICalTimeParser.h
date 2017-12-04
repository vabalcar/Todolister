#pragma once
#include "TimeParser.h"

class ICalTimeParser : public TimeParser {
public:
	timePtr tryParse(const string& s) const;
};