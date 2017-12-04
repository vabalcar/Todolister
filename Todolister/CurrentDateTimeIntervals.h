#pragma once
#include "DateTimeInterval.h"
#include "CurrentDateTime.h"

class CurrentDateTimeIntervals {
public:
	dtIntPtr getCurrentYear();
	dtIntPtr getCurrentMonth();
	dtIntPtr getCurrentDay();
	dtIntPtr getCurrentHour();
	dtIntPtr getCurrentMinute();
private:
	CurrentDateTime currentDateTime_;
};