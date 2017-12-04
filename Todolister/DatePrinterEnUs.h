#pragma once
#include "DatePrinter.h"

class DatePrinterEnUs : public DatePrinter {
public:
	void print(const Date& date, ostream& out) const;
private:
	const char DELIMITER_DATE_EN_US = '/';
};