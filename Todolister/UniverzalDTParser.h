#pragma once
#include "DateTimeParser.h"
#include "FormatRegister.h"

class UniverzalDTParser {
public:
	UniverzalDTParser(const FormatRegister& formatRegister) : formatRegister_(formatRegister) {}
	dateTimePtr tryParse(const string& source) const;
private:
	const FormatRegister& formatRegister_;
	DateTimeParser parser_;
};