#include "DateTimePrinter.h"

void DateTimePrinter::print(const DateTime& dateTime, ostream& out, const Format& format) const {
	bool firstPrint = true;
	for (size_t i = 0; i < format.getDateTimeOrder().size(); i++) {
		switch (format.getDateTimeOrder()[i]) {
		case DateTime::DATE_ID:
			if (!firstPrint) {
				out << format.getDateTimeDelimiters();
			}
			else {
				firstPrint = false;
			}
			format.getDatePrinter().print(dateTime.getDate(), out);
			break;
		case DateTime::TIME_ID:
			if (!firstPrint) {
				out << format.getDateTimeDelimiters();
			}
			else {
				firstPrint = false;
			}
			format.getTimePrinter().print(dateTime.getTime(), out);
			break;
		default:
			return;//TODO: Exception
		}
	}
}