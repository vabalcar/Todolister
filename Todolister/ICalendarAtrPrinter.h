#pragma once
#include "AtrPrinter.h"

class ICalendarAtrPrinter : public AtrPrinter {
public:
	void print(const string& argName, const string& argVal, ostream& out) const;
};