#include "EventParser.h"

bool EventParser::tryParseAtr(vector<string>& tokens, size_t& tokenIndex, const char tokenId, const Layout& layout, const Format& format) {
	if (TOIParser::tryParseAtr(tokens, tokenIndex, tokenId, layout, format)) return true;
	switch (tokenId) {
	case Event::START_DATETIME_ID:
		startDateTime = parseDateTime(tokens, tokenIndex, layout, format);
		return true;
	case Event::END_DATETIME_ID:
		endDateTime = parseDateTime(tokens, tokenIndex, layout, format);
		return true;
	default:
		return false;
	}
}
toiPtr EventParser::createToi() {
	return make_shared<Event>(move(uid), move(dateTimeStamp), move(startDateTime), move(endDateTime), move(name));
}