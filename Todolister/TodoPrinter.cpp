#include "TodoPrinter.h"

bool TodoPrinter::print(const TimeOrganizerIndividual& toi, char atrToPrintId, ostream& out, const Layout& layout, const Format& format) {
	if (TOIPrinter::print(toi, atrToPrintId, out, layout, format)) return true;
	const Todo& todo = static_cast<const Todo&>(toi);
	switch (atrToPrintId) {
	case Todo::DUE_DATETIME_ID:
		printDateTimeAtr(Todo::DUE_DATETIME_ID, todo.getDueDate(), out, layout, format);
		return true;
	default:
		return false;
	}
}