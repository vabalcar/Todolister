#pragma once
#include "DateParser.h"
#include "StringUtils.h"

class DateParserCsCz : public DateParser {
public:
	datePtr tryParse(const string& s) const;
private:
	const char DATE_DELIMITER = '.';
	const short int YEAR_POSITION = 2;
	const short int MONTH_POSITION = 1;
	const short int DAY_POSITION = 0;
};