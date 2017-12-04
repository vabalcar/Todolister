#include "DateTimeParser.h"
#include "CurrentDateTime.h"

dateTimePtr DateTimeParser::tryParse(const string& source, const Format& format) const {
	if (source.empty()) return nullptr;
	if (source == "now") {
		return CurrentDateTime().now();
	}
	else if (source == "today") {
		return CurrentDateTime().today();
	}
	datePtr date = nullptr;
	timePtr time = nullptr;
	vector<string> tokens = split(source, format.getDateTimeDelimiters());
	if (tokens.size() != format.getDateTimeOrder().size()) return nullptr;
	for (size_t i = 0; i < format.getDateTimeOrder().size(); i++) {
		switch (format.getDateTimeOrder()[i]) {
		case DateTime::DATE_ID:
			date = format.getDateParser().tryParse(tokens[i]);
			break;
		case DateTime::TIME_ID:
			time = format.getTimeParser().tryParse(tokens[i]);
			break;
		default:
			return nullptr;//TODO: Exception
		}
	}
	if (date == nullptr
		|| time == nullptr) {
		return nullptr;
	}
	return make_unique<DateTime>(move(date), move(time));
}