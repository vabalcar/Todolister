#include "DateTime.h"

DateTime::DateTime(const DateTime& anotherDateTime) {
	if (anotherDateTime.date_ == nullptr) {
		date_ = nullptr;
	}
	else {
		date_ = make_unique<Date>(anotherDateTime.date_->getYear(),
			anotherDateTime.date_->getMonth(),
			anotherDateTime.date_->getDay());
	}
	if (anotherDateTime.time_ == nullptr) {
		time_ = nullptr;
	}
	else {
		time_ = make_unique<Time>(anotherDateTime.time_->getHours(),
			anotherDateTime.time_->getMinutes(),
			anotherDateTime.time_->getSeconds());
	}
}
bool DateTime::operator<(const DateTime& anotherDateTime) const {
	if (date_ != nullptr && anotherDateTime.date_ != nullptr) {
		if (*date_ < *anotherDateTime.date_) return true;
		if (*date_ > *anotherDateTime.date_) return false;
	}
	if (time_ != nullptr && anotherDateTime.time_ != nullptr) {
		if (*time_ < *anotherDateTime.time_) return true;
	}
	return false;
}
bool DateTime::operator==(const DateTime& anotherDateTime) const {
	if (date_ != nullptr && anotherDateTime.date_ != nullptr) {
		if (!(*date_ == *anotherDateTime.date_)) return false;
	}
	if (time_ != nullptr && anotherDateTime.time_ != nullptr) {
		return *time_ == *anotherDateTime.time_;
	}
	return true;
}
bool DateTime::operator>(const DateTime& anotherDateTime) const {
	return !(*this < anotherDateTime || *this == anotherDateTime);
}
bool DateTime::operator<=(const DateTime& anotherDateTime) const {
	return *this < anotherDateTime || *this == anotherDateTime;
}
bool DateTime::operator>=(const DateTime& anotherDateTime) const {
	return *this > anotherDateTime || *this == anotherDateTime;
}