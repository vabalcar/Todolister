#pragma once
#include "Format.h"

#include "DateParserEnUs.h"
#include "DatePrinterEnUs.h"
#include "TimeParserEnUs.h"
#include "TimePrinterEnUs.h"

class EnUs : public Format {
public:
	const string getDateTimeDelimiters() const {
		return DATE_TIME_DELIMTERS;
	}
	const string getDateTimeOrder() const {
		return DATE_TIME_ORDER;
	}

	const DateParser& getDateParser() const {
		return dateParserEnUs;
	}
	const TimeParser& getTimeParser() const {
		return timeParserEnUs;
	}

	const DatePrinter& getDatePrinter() const {
		return datePrinterEnUs;
	}
	const TimePrinter& getTimePrinter() const {
		return timePrinterEnUs;
	}
private:
	DateParserEnUs dateParserEnUs;
	DatePrinterEnUs datePrinterEnUs;
	TimeParserEnUs timeParserEnUs;
	TimePrinterEnUs timePrinterEnUs;

	const string DATE_TIME_DELIMTERS = " ";
	const string DATE_TIME_ORDER = "TD";
};