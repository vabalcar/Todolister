#pragma once
#include "Format.h"
#include "ICalDateParser.h"
#include "ICalDatePrinter.h"
#include "ICalTimeParser.h"
#include "ICalTimePrinter.h"

class ICalendarFormat : public Format {
public:
	const string getDateTimeDelimiters() const {
		return dateTimeDelimiter_;
	}
	const string getDateTimeOrder() const {
		return dateTimeOrder_;
	}
	const DateParser& getDateParser() const {
		return iCalDateParser_;
	}
	const TimeParser& getTimeParser() const {
		return iCalTimeParser_;
	}
	const DatePrinter& getDatePrinter() const {
		return iCalDatePrinter_;
	}
	const TimePrinter& getTimePrinter() const {
		return iCalTimePrinter_;
	}
private:
	ICalDateParser iCalDateParser_;
	ICalDatePrinter iCalDatePrinter_;
	ICalTimeParser iCalTimeParser_;
	ICalTimePrinter iCalTimePrinter_;

	const string atrsDelimiter_ = "\r\n";
	const string dateTimeDelimiter_ = "T";
	const string dateTimeOrder_ = "DT";
};