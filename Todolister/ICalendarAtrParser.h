#pragma once
#include "AtrParser.h"
#include "StringUtils.h"

class ICalendarAtrParser : public AtrParser {
public:
	stringPtr getName(string& source) const;
	stringPtr getValue(string& source) const;
};