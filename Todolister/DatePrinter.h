#pragma once
#include <iostream>

#include "Date.h"

class DatePrinter {
public:
	virtual void print(const Date& date, ostream& out) const = 0;

	virtual ~DatePrinter() = default;
};