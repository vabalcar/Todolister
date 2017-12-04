#include "ICalendarLayout.h"
#include <sstream>

ICalendarLayout::ICalendarLayout(const string& defaultOrder) {
	orders.insert(make_pair("", defaultOrder));
	orders.insert(make_pair("VEVENT", defaultOrder));
	orders.insert(make_pair("VTODO", defaultOrder));
	namer_.registerName('u', "UID");
	namer_.registerName('c', "DTSTAMP");
	namer_.registerName('s', "DTSTART");
	namer_.registerName('e', "DTEND");
	namer_.registerName('n', "SUMMARY");
}
string ICalendarLayout::getNextTOISource(istream& in) {
	determineOrder(in);
	stringstream toiSource;
	stringPtr name;
	string line;
	while ((name = atrParser_.getName(line = readLine(in))) != nullptr && *name != "END") {
		if (*name == "BEGIN") {
			toiSource.str("");
			toiSource.clear();
		}
		else {
			toiSource << line << endl;
		}
	}
	return toiSource.str();
}
void ICalendarLayout::determineOrder(istream& in) {
	streampos pos = in.tellg();
	stringstream order;
	string line;
	stringPtr name, objectName;
	while ((name = atrParser_.getName(line = readLine(in))) != nullptr && *name != "END") {
		if (*name == "BEGIN") {
			((objectName = atrParser_.getValue(line)) != nullptr) ? currentObject_ = *objectName : "";
			order.str("");
			order.clear();
		}
		else {
			order << namer_.getID(*atrParser_.getName(line));
		}
	}
	in.seekg(pos);
	orders[currentObject_] = order.str();
}