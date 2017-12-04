#include "UniverzalDTParser.h"

dateTimePtr UniverzalDTParser::tryParse(const string& source) const {
	for (auto it = formatRegister_.begin(); it != formatRegister_.end(); ++it) {
		dateTimePtr parsedDateTime = parser_.tryParse(source, *(it->second));
		if (parsedDateTime != nullptr) return parsedDateTime;
		datePtr parsedDate = it->second->getDateParser().tryParse(source);
		timePtr parsedTime = nullptr;
		if (parsedDate != nullptr) return make_unique<DateTime>(move(parsedDate), move(parsedTime));
		parsedTime = it->second->getTimeParser().tryParse(source);
		if (parsedTime != nullptr) return make_unique<DateTime>(move(parsedDate), move(parsedTime));
	}
	return nullptr;
}