#include "TimeOrganizerPrinter.h"

void TimeOrgranizerPrinter::print(const TimeOrganizer& timeOrganizer, ostream& out, const Layout& layout, const Format& format) {
	out << layout.getHeader(toiPrinter_.getTOSign());
	for (size_t i = 0; i < timeOrganizer.size(); i++) {
		out << layout.getTOIStart(toiPrinter_.getTOISign());
		toiPrinter_.print(timeOrganizer[i], out, layout, format);
		out << layout.getTOIEnd(toiPrinter_.getTOISign());
		out << layout.getTOIDelimiters();
	}
	out << layout.getFooter(toiPrinter_.getTOSign());
}