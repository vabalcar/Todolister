#pragma once
#include "Format.h"
#include "DateParserCsCz.h"
#include "DatePrinterCsCz.h"
#include "TimeParserCsCz.h"
#include "TimePrinterCsCz.h"

class CsCz : public Format {
public:
	const string getDateTimeDelimiters() const {
		return DATE_TIME_DELIMITERS;
	}
	const string getDateTimeOrder() const {
		return DATE_TIME_ORDER;
	}

	const DateParser& getDateParser() const {
		return dateParserCsCz;
	}
	const TimeParser& getTimeParser() const {
		return timeParserCsCz;
	}

	const DatePrinter& getDatePrinter() const {
		return datePrinterCsCz;
	}
	const TimePrinter& getTimePrinter() const {
		return timePrinterCsCz;
	}
private:
	DateParserCsCz dateParserCsCz;
	DatePrinterCsCz datePrinterCsCz;
	TimeParserCsCz timeParserCsCz;
	TimePrinterCsCz timePrinterCsCz;

	const string DATE_TIME_DELIMITERS = " ";
	const string DATE_TIME_ORDER = "TD";
};