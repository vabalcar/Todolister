#pragma once
#include "Date.h"
#include "Time.h"

class DateTime {
public:
	static const char DATE_ID = 'D';
	static const char TIME_ID = 'T';

	DateTime(datePtr date, timePtr time) : date_(move(date)), time_(move(time)) {}
	DateTime(const DateTime& anotherDateTime);
	bool operator<(const DateTime& anotherDateTime) const;
	bool operator==(const DateTime& anotherDateTime) const;
	bool operator>(const DateTime& anotherDateTime) const;
	bool operator<=(const DateTime& anotherDateTime) const;
	bool operator>=(const DateTime& anotherDateTime) const;
	const Date getDate() const {
		return *date_;
	}
	const Time getTime() const {
		return *time_;
	}
	void setDate(datePtr date) {
		date_ = move(date);
	}
	void setTime(timePtr time) {
		time_ = move(time);
	}
	void deleteDate() {
		date_ = nullptr;
	}
	void deleteTime() {
		time_ = nullptr;
	}
private:
	datePtr date_;
	timePtr time_;
};

typedef unique_ptr<DateTime> dateTimePtr;