#pragma once
#include "TOIParser.h"
#include "Event.h"

class EventParser : public TOIParser {
protected:
	dateTimePtr startDateTime = nullptr;
	dateTimePtr endDateTime = nullptr;

	bool tryParseAtr(vector<string>& tokens, size_t& tokenIndex, const char tokenId, const Layout& layout, const Format& format);
	toiPtr createToi();
};
