#pragma once
#include "TimePrinter.h"

class TimePrinterCsCz : public TimePrinter {
public:
	void print(const Time& time, ostream& out) const;
};