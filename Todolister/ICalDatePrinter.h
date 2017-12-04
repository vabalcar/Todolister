#pragma once
#include "DatePrinter.h"

class ICalDatePrinter : public DatePrinter {
public:
	void print(const Date& date, ostream& out) const;
};