#include "ICalTimeParser.h"

timePtr ICalTimeParser::tryParse(const string& s) const {
	try {
		unsigned short int hours = stoi(s.substr(0, 2));
		unsigned short int minutes = stoi(s.substr(2, 2));
		unsigned short int seconds = stoi(s.substr(4, 2));
		return make_unique<Time>(hours, minutes, seconds);
	}
	catch (logic_error) {
		return nullptr;
	}
}