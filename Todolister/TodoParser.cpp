#include "TodoParser.h"

bool TodoParser::tryParseAtr(vector<string>& tokens, size_t& tokenIndex, const char tokenId, const Layout& layout, const Format& format) {
	if (TOIParser::tryParseAtr(tokens, tokenIndex, tokenId, layout, format)) return true;
	switch (tokenId) {
	case Todo::DUE_DATETIME_ID:
		dueDate_ = parseDateTime(tokens, tokenIndex, layout, format);
		return true;
	default:
		return false;
	}
}
toiPtr TodoParser::createToi() {
	return make_shared<Todo>(move(uid), move(dateTimeStamp), move(dueDate_), move(name));
}