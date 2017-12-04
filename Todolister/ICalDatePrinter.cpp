#include "ICalDatePrinter.h"
#include <iomanip>

void ICalDatePrinter::print(const Date& date, ostream& out) const {
	out << setw(4) << setfill('0') << right << date.getYear()
		<< setw(2) << setfill('0') << right << date.getMonth()
		<< setw(2) << setfill('0') << right << date.getDay();
}