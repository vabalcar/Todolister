#include "DateParserCsCz.h"

datePtr DateParserCsCz::tryParse(const string& s) const {
	vector<int> parsedInts = parseInts(s, DATE_DELIMITER);
	if (parsedInts.size() != 3) return nullptr;
	return make_unique<Date>(parsedInts[YEAR_POSITION], parsedInts[MONTH_POSITION], parsedInts[DAY_POSITION]);
}