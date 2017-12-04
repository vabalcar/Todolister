#include "DatePrinterCsCz.h"

void DatePrinterCsCz::print(const Date& date, ostream& out) const {
	out << date.getDay() << '.' << date.getMonth() << '.' << date.getYear();
}