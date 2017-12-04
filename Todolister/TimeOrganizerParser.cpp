#include "TimeOrganizerParser.h"

TimeOrganizer TimeOrganizerParser::tryParse(istream& source, Layout& layout, const Format& format) {
	string toiSource = layout.getNextTOISource(source);
	TimeOrganizer timeOrganizer;
	while (toiSource.size() != 0) {
		toiPtr toi = toiParser_.tryParse(toiSource, layout, format);
		if (toi != nullptr) timeOrganizer.addEvent(toi);
		toiSource = layout.getNextTOISource(source);
	}
	return timeOrganizer;
}