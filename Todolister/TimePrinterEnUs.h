#pragma once
#include "TimePrinter.h"

class TimePrinterEnUs : public TimePrinter {
public:
	void print(const Time& time, ostream& out) const;
};