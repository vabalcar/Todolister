#include "DatePrinterEnUs.h"

void DatePrinterEnUs::print(const Date& date, ostream& out) const {
	out << date.getMonth() << DELIMITER_DATE_EN_US << date.getDay() << DELIMITER_DATE_EN_US << date.getYear();
}