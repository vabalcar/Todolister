#pragma once
#include "DateTime.h"

class DateTimeInterval {
public:
	DateTimeInterval(dateTimePtr start, dateTimePtr end) : start_(move(start)), end_(move(end)) {}
	DateTimeInterval(const DateTimeInterval& anotherDTI) {
		start_ = make_unique<DateTime>(*anotherDTI.start_);
		end_ = make_unique<DateTime>(*anotherDTI.end_);
	}
	const DateTime& getStart() const { return *start_; }
	const DateTime& getEnd() const { return *end_; }
	bool isValid() { return start_ < end_; }
private:
	dateTimePtr start_;
	dateTimePtr end_;
};

typedef unique_ptr<DateTimeInterval> dtIntPtr;