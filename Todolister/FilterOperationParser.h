#pragma once
#include "TOOParser.h"
#include "FilterParserRegister.h"

class FilterOperationParser : public TOOParser {
public:
	FilterOperationParser(const FilterParserRegister& filterParserRegister) : filterParserRegister_(filterParserRegister) {}
	toopPtr tryParse(const vector<string>& args, size_t& index) const;

	virtual ~FilterOperationParser() = default;
protected:
	const FilterParserRegister& filterParserRegister_;
};