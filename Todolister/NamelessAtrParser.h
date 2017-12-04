#pragma once
#include "AtrParser.h"

class NamelessAtrParser : public AtrParser {
public:
	stringPtr getName(string& source) const {
		return nullptr;
	}
	stringPtr getValue(string& source) const;
};