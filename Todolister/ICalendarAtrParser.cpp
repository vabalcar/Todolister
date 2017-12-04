#include "ICalendarAtrParser.h"
#include <sstream>

stringPtr ICalendarAtrParser::getName(string& source) const {
	vector<string> tokens = split(source, ":");
	if (tokens.size() < 2) return nullptr;
	return make_unique<string>(tokens[0]);
}
stringPtr ICalendarAtrParser::getValue(string& source) const {
	vector<string> tokens = split(source, ":");
	if (tokens.size() < 2) return nullptr;
	stringstream value;
	for (size_t i = 1; i < tokens.size(); i++) {
		value << tokens[i];
	}
	return make_unique<string>(value.str());
}