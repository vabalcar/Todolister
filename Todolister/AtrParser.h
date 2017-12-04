#pragma once
#include "StringUtils.h"

class AtrParser {
public:
	virtual stringPtr getName(string& source) const = 0;
	virtual stringPtr getValue(string& source) const = 0;

	virtual ~AtrParser() = default;
};