#pragma once
#include "FilterParser.h"
#include "UniverzalDTParser.h"

class DateTimeFilterParser : public FilterParser {
public:
	DateTimeFilterParser(const FormatRegister& formatRegister) : dateTimeParser_(formatRegister) {}
	filterPtr tryParse(const vector<string>& compareType, size_t& index) const;
private:
	UniverzalDTParser dateTimeParser_;
};