#pragma once
#include "TimeOrganizer.h"
#include "TOIParser.h"

class TimeOrganizerParser {
public:
	TimeOrganizerParser(TOIParser& toiParser) : toiParser_(toiParser) {}
	TimeOrganizer tryParse(istream& source, Layout& layout, const Format& format);
private:
	TOIParser& toiParser_;
};