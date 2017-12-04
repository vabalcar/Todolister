#pragma once
#include "TimeOrganizerOperation.h"

class TOOParser {
public:
	virtual toopPtr tryParse(const vector<string>& args, size_t& index) const = 0;

	virtual ~TOOParser() = default;
};

typedef unique_ptr<TOOParser> tooParserPtr;