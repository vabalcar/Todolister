#pragma once
#include "TimeOrganizer.h"
#include "TOIPrinter.h"

class TimeOrgranizerPrinter {
public:
	TimeOrgranizerPrinter(TOIPrinter& toiPrinter) : toiPrinter_(toiPrinter) {}
	void print(const TimeOrganizer& timeOrganizer, ostream& out, const Layout& layout, const Format& format);
private:
	TOIPrinter& toiPrinter_;
};