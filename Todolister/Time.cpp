#include "Time.h"

bool Time::operator<(const Time& anotherTime) const {
	if (hours_ < anotherTime.hours_) return true;
	if (hours_ > anotherTime.hours_) return false;
	if (minutes_ < anotherTime.minutes_) return true;
	if (minutes_ > anotherTime.minutes_) return false;
	if (seconds_ < anotherTime.seconds_) return true;
	return false;
}
bool Time::operator==(const Time& anotherTime) const {
	return hours_ == anotherTime.hours_
		&& minutes_ == anotherTime.minutes_
		&& seconds_ == anotherTime.seconds_;
}
bool Time::operator>(const Time& anotherTime) const {
	return !(*this < anotherTime || *this == anotherTime);
}