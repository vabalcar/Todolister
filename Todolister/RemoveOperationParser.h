#pragma once
#include "FilterOperationParser.h"

class RemoveOperationParser : public FilterOperationParser {
public:
	RemoveOperationParser(const FilterParserRegister& filterParserRegister) : FilterOperationParser(filterParserRegister) {}
	toopPtr tryParse(const vector<string>& args, size_t& index) const;
};