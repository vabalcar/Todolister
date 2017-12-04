#pragma once
#include "TOIParser.h"
#include "Todo.h"

class TodoParser : public TOIParser {
protected:
	dateTimePtr dueDate_ = nullptr;

	bool tryParseAtr(vector<string>& tokens, size_t& tokenIndex, const char tokenId, const Layout& layout, const Format& format);
	toiPtr createToi();
};