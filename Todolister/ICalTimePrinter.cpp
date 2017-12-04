#include "ICalTimePrinter.h"
#include <iomanip>

void ICalTimePrinter::print(const Time& time, ostream& out) const {
	out << setw(2) << setfill('0') << right << time.getHours()
		<< setw(2) << setfill('0') << right << time.getMinutes()
		<< setw(2) << setfill('0') << right << time.getSeconds();
}