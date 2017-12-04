#include "TOIPrinter.h"
#include <sstream>

const string TOIPrinter::EMPTY_FIELD_MARK = "null";

void TOIPrinter::print(const TimeOrganizerIndividual& toi, ostream& out, const Layout& layout, const Format& format) {
	const string& atrsOrder = layout.getTOIAtrsOrder();
	for (size_t i = 0; i < atrsOrder.size(); i++) {
		printingLast_ = (i + 1 >= atrsOrder.size() && !layout.argDelimiterAfterLastArg());
		print(toi, atrsOrder[i], out, layout, format);
	}
}
bool TOIPrinter::print(const TimeOrganizerIndividual& toi, char atrToPrintId, ostream& out, const Layout& layout, const Format& format) {
	switch (atrToPrintId) {
	case TimeOrganizerIndividual::UID_ID:
		printAtr(TimeOrganizerIndividual::UID_ID, toi.getUid(), out, layout);
		return true;
	case TimeOrganizerIndividual::DATETIME_STAMP_ID:
		printDateTimeAtr(TimeOrganizerIndividual::DATETIME_STAMP_ID, toi.getDateTimeStamp(), out, layout, format);
		return true;
	case TimeOrganizerIndividual::NAME_ID:
		printAtr(TimeOrganizerIndividual::NAME_ID, toi.getName(), out, layout);
		return true;
	default:
		return false;
	}
}
void TOIPrinter::printAtr(const char& atrId, const string& atrVal, ostream& out, const Layout& layout) {
	if (emptyVals_.isEmptyString(atrVal)) {
		layout.getAtrPrinter().print(layout.getAtrNamer()[atrId], EMPTY_FIELD_MARK, out);
	}
	else {
		layout.getAtrPrinter().print(layout.getAtrNamer()[atrId], atrVal, out);
	}
	if (!printingLast_) out << layout.getOutputTOIAtrsDelimiters();
	else printingLast_ = false;
}
void TOIPrinter::printDateTimeAtr(const char& atrId, const DateTime& atrVal, ostream& out, const Layout& layout, const Format& format) {
	if (emptyVals_.isEmptyDateTime(atrVal)) {
		printAtr(atrId, EMPTY_FIELD_MARK, out, layout);
	}
	else {
		stringstream s;
		dateTimePrinter.print(atrVal, s, format);
		printAtr(atrId, s.str(), out, layout);
	}
}