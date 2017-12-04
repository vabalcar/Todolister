#pragma once
#include "TimePrinter.h"

class ICalTimePrinter : public TimePrinter {
public:
	void print(const Time& time, ostream& out) const;
};