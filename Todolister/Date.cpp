#include "Date.h"

bool Date::operator<(const Date& anotherDate) const {
	if (year_ < anotherDate.year_) return true;
	if (year_ > anotherDate.year_) return false;
	if (month_ < anotherDate.month_) return true;
	if (month_ > anotherDate.month_) return false;
	if (day_ < anotherDate.day_) return true;
	return false;
}
bool Date::operator==(const Date& anotherDate) const {
	return year_ == anotherDate.year_
		&& month_ == anotherDate.month_
		&& day_ == anotherDate.day_;
}
bool Date::operator>(const Date& anotherDate) const {
	return !(*this < anotherDate || *this == anotherDate);
}