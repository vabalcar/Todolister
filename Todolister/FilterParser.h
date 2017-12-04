#pragma once
#include "TimeOrganizer.h"

class FilterParser {
public:
	virtual filterPtr tryParse(const vector<string>& args, size_t& index) const = 0;

	virtual ~FilterParser() = default;
};

typedef unique_ptr<FilterParser> filterParserPtr;