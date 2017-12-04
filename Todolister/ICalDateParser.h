#pragma once
#include "DateParser.h"

class ICalDateParser : public DateParser {
public:
	datePtr tryParse(const string& s) const;
};