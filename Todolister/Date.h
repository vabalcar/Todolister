#pragma once
#include <memory>

using namespace std;

class Date {
public:
	Date(signed int year, unsigned short int month, unsigned short day) : year_(year), month_(month), day_(day) {}
	bool operator<(const Date& anotherDate) const;
	bool operator==(const Date& anotherDate) const;
	bool operator>(const Date& anotherDate) const;
	signed int getYear() const {
		return year_;
	}
	unsigned short int getMonth() const {
		return month_;
	}
	unsigned short int getDay() const {
		return day_;
	}
	void setYear(signed int year) {
		year_ = year;
	}
	void setMonth(unsigned short int month) {
		month_ = month;
	}
	void setDay(unsigned short int day) {
		day_ = day;
	}
private:
	signed int year_;
	unsigned short int month_;
	unsigned short int day_;
};

typedef unique_ptr<Date> datePtr;