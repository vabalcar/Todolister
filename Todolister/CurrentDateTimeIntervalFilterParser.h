#pragma once
#include "FilterParser.h"

class CurrentDateTimeIntervalFilterParser : public FilterParser {
public:
	filterPtr tryParse(const vector<string>& args, size_t& index) const;
private:
};