#pragma once
#include <string>

#include "DateTime.h"
#include "Format.h"
#include "TimeOrganizer.h"

class DateTimeParser {
public:
	dateTimePtr tryParse(const string& source, const Format& format) const;
};