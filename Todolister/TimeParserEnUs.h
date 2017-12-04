#pragma once
#include "TimeParser.h"

class TimeParserEnUs : public TimeParser {
public:
	timePtr tryParse(const string& s) const;
private:
	const char TIME_DELIMITER = ':';
	const short int HOURS_POSITION = 0;
	const short int MINUTES_POSITION = 1;
	const short int SECONDS_POSTION = 2;
};