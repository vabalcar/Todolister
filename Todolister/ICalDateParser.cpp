#include "ICalDateParser.h"

datePtr ICalDateParser::tryParse(const string& s) const {
	try {
		int year = stoi(s.substr(0, 4));
		unsigned short int month = stoi(s.substr(4, 2));
		unsigned short int day = stoi(s.substr(6, 2));
		return make_unique<Date>(year, month, day);
	}
	catch (logic_error) {
		return nullptr;
	}
}