#pragma once
#include "TimeOrganizerIndividual.h"
#include "DateTimeParser.h"
#include "Layout.h"

class TOIParser {
public:
	static const char SKIP_ID = '_';
	toiPtr tryParse(string& source, const Layout& layout, const Format& format);

	virtual ~TOIParser() = default;
protected:
	DateTimeParser dateTimeParser;

	stringPtr uid = nullptr;
	dateTimePtr dateTimeStamp = nullptr;
	stringPtr name = nullptr;

	virtual bool tryParseAtr(vector<string>& tokens, size_t& tokenIndex, const char tokenId, const Layout& layout, const Format& format);
	stringPtr parseAtrVal(vector<string>& tokens, size_t& tokenIndex, const Layout& layout) const;
	dateTimePtr parseDateTime(vector<string>& tokens, size_t& index, const Layout& layout, const Format& format) const;
	virtual toiPtr createToi() = 0;
private:
	stringPtr parseAtrVal(string& source, const Layout& layout) const;
};

typedef unique_ptr<TOIParser> toiParserPtr;