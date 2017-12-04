#pragma once
#include "TOIPrinter.h"
#include "Event.h"

class EventPrinter : public TOIPrinter {
public:
	string getTOISign() const { return "event"; }
	string getTOSign() const { return "calendar"; }
protected:
	bool print(const TimeOrganizerIndividual& toi, char atrToPrintId, ostream& out, const Layout& layout, const Format& format);
};