#include "EmptyVals.h"

dateTimePtr EmptyVals::createEmptyDateTime() const {
	datePtr emptyDate = make_unique<Date>(INT_MIN, 0, 0);
	timePtr emptyTime = make_unique<Time>(SHRT_MAX, 0, 0);
	return make_unique<DateTime>(move(emptyDate), move(emptyTime));
}
bool EmptyVals::isEmptyDateTime(const DateTime& dateTime) const {
	return dateTime == *emptyDateTime_;
}
stringPtr EmptyVals::createEmptyString() const {
	return make_unique<string>("");
}
bool EmptyVals::isEmptyString(const string& s) const {
	return s == *emptyString_;
}