#pragma once
#include "DatePrinter.h"

class DatePrinterCsCz : public DatePrinter {
public:
	void print(const Date& date, ostream& out) const;
};