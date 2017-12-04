#include "CurrentDateTime.h"
#include <time.h>

void CurrentDateTime::update() {
	time_t rawtime;
	struct tm * systemTime;
	time(&rawtime);
	systemTime = localtime(&rawtime);

	datePtr currentDate = make_unique<Date>(systemTime->tm_year + 1900, systemTime->tm_mon + 1, systemTime->tm_mday);
	timePtr currentTime = make_unique<Time>(systemTime->tm_hour, systemTime->tm_min, systemTime->tm_min);
	currentDateTime_ = make_unique<DateTime>(move(currentDate), move(currentTime));
}
dateTimePtr CurrentDateTime::today() const {
	dateTimePtr today = make_unique<DateTime>(*currentDateTime_);
	today->deleteTime();
	return today;
}
