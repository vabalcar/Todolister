#pragma once
#include "DateTime.h"
#include "Format.h"

class DateTimePrinter {
public:
	void print(const DateTime& dateTime, ostream& out, const Format& format) const;
};