#pragma once
#include "ICalendarAtrPrinter.h"

void ICalendarAtrPrinter::print(const string& argName, const string& argVal, ostream& out) const {
	out << argName << ":" << argVal;
}