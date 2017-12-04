#include "EventPrinter.h"

bool EventPrinter::print(const TimeOrganizerIndividual& toi, char atrToPrintId, ostream& out, const Layout& layout, const Format& format) {
	if (TOIPrinter::print(toi, atrToPrintId, out, layout, format)) return true;
	const Event& event = static_cast<const Event&>(toi);
	switch (atrToPrintId) {
	case Event::START_DATETIME_ID:
		printDateTimeAtr(Event::START_DATETIME_ID, event.getStartDateTime(), out, layout, format);
		return true;
	case Event::END_DATETIME_ID:
		printDateTimeAtr(Event::END_DATETIME_ID, event.getEndDateTime(), out, layout, format);
		return true;
	default:
		return false;
	}
}