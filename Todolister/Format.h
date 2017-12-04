#pragma once
#include "DateParser.h"
#include "DatePrinter.h"
#include "TimeParser.h"
#include "TimePrinter.h"

class Format {
public:
	virtual const string getDateTimeDelimiters() const = 0;
	virtual const string getDateTimeOrder() const = 0;

	virtual const DateParser& getDateParser() const = 0;
	virtual const TimeParser& getTimeParser() const = 0;

	virtual const DatePrinter& getDatePrinter() const = 0;
	virtual const TimePrinter& getTimePrinter() const = 0;

	virtual ~Format() = default;
};

typedef unique_ptr<Format> formatPtr;