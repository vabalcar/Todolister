#pragma once
#include "FilterParser.h"

class TopFilterParser : public FilterParser {
public:
	filterPtr tryParse(const vector<string>& compareType, size_t& index) const;
};