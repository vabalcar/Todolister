#pragma once
#include "TOIPrinter.h"
#include "Todo.h"

class TodoPrinter : public TOIPrinter {
public:
	string getTOISign() const { return "todo"; }
	string getTOSign() const { return "calendar"; }
protected:
	bool print(const TimeOrganizerIndividual& toi, char atrToPrintId, ostream& out, const Layout& layout, const Format& format);
};