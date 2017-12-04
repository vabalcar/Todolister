#include "TOIParser.h"
#include <sstream>

toiPtr TOIParser::tryParse(string& source, const Layout& layout, const Format& format) {
	vector<string> tokens = split(source, layout.getInputTOIAtrsDelimiters());
	const string& order = layout.getTOIAtrsOrder();

	size_t currentTokenIndex = 0;
	for (size_t i = 0; i < order.size(); i++) {
		tryParseAtr(tokens, currentTokenIndex, order[i], layout, format);
	}
	return createToi();
}

bool TOIParser::tryParseAtr(vector<string>& tokens, size_t& tokenIndex, const char tokenId, const Layout& layout, const Format& format) {
	switch (tokenId) {
	case SKIP_ID:
		parseAtrVal(tokens, tokenIndex, layout);
		return true;
	case TimeOrganizerIndividual::UID_ID:
		uid = parseAtrVal(tokens, tokenIndex, layout);
		return true;
	case TimeOrganizerIndividual::DATETIME_STAMP_ID:
		dateTimeStamp = parseDateTime(tokens, tokenIndex, layout, format);
		return true;
	case TimeOrganizerIndividual::NAME_ID:
		name = parseAtrVal(tokens, tokenIndex, layout);
		return true;
	default:
		return false;
	}
}
stringPtr TOIParser::parseAtrVal(vector<string>& tokens, size_t& tokenIndex, const Layout& layout) const {
	if (tokenIndex >= tokens.size()) return nullptr;
	return parseAtrVal(tokens[tokenIndex++], layout);
}
dateTimePtr TOIParser::parseDateTime(vector<string>& tokens, size_t& index, const Layout& layout, const Format& format) const {
	for (size_t i = 0; i < layout.getInputTOIAtrsDelimiters().size(); i++) {
		for (size_t j = 0; j < format.getDateTimeDelimiters().size(); j++) {
			if (layout.getInputTOIAtrsDelimiters()[i] == format.getDateTimeDelimiters()[j]) {
				if (index + 1 == tokens.size()) {
					return nullptr;
				}
				stringstream dateTime;
				dateTime << tokens[index] << format.getDateTimeDelimiters();
				index++;
				dateTime << tokens[index];
				index++;
				stringPtr parsedAtrVal = parseAtrVal(dateTime.str(), layout);
				if (parsedAtrVal == nullptr) return nullptr;
				return dateTimeParser.tryParse(*parsedAtrVal, format);
			}
		}
	}
	stringPtr parsedAtrVal = parseAtrVal(tokens, index, layout);
	if (parsedAtrVal == nullptr) return nullptr;
	return dateTimeParser.tryParse(*parsedAtrVal, format);
}
stringPtr TOIParser::parseAtrVal(string& source, const Layout& layout) const {
	return layout.getAtrParser().getValue(source);
}