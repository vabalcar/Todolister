#include "TimeParserCsCz.h"

timePtr TimeParserCsCz::tryParse(const string& s) const {
	vector<int> parsedInts = parseInts(s, TIME_DELIMITER);
	if (parsedInts.size() != 3) return nullptr;
	return make_unique<Time>(parsedInts[0], parsedInts[1], parsedInts[2]);
}