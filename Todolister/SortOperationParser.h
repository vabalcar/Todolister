#pragma once
#include "TOOParser.h"

class SortOperationParser : public TOOParser {
public:
	toopPtr tryParse(const vector<string>& args, size_t& index) const;
};