#pragma once
#include <memory>

using namespace std;

class Time {
public:
	Time(unsigned short int hours, unsigned short int minutes, unsigned short int seconds) : hours_(hours), minutes_(minutes), seconds_(seconds) {}
	bool operator<(const Time& anotherTime) const;
	bool operator==(const Time& anotherTime) const;
	bool operator>(const Time& anotherTime) const;
	unsigned short int getHours() const {
		return hours_;
	}
	unsigned short int getMinutes() const {
		return minutes_;
	}
	unsigned short int getSeconds() const {
		return seconds_;
	}
	void setHours(unsigned short int hours) {
		hours_ = hours;
	}
	void setMinutes(unsigned short int minutes) {
		minutes_ = minutes;
	}
	void setSeconds(unsigned short int seconds) {
		seconds_ = seconds;
	}
private:
	unsigned short int hours_;
	unsigned short int minutes_;
	unsigned short int seconds_;
};

typedef unique_ptr<Time> timePtr;