#include "TimeOrganizerIndividual.h"

TimeOrganizerIndividual::TimeOrganizerIndividual(stringPtr uid, dateTimePtr dateTimeStamp, stringPtr name)
	: uid_(move(uid)), dateTimeStamp_(move(dateTimeStamp)), name_(move(name)) {
	setEmptyIfNull(uid_);
	setEmptyIfNull(dateTimeStamp_);
	setEmptyIfNull(name_);
}
bool TimeOrganizerIndividual::operator<(const TimeOrganizerIndividual& anotherTOI) const {
	return *uid_ < *anotherTOI.uid_;
}
bool TimeOrganizerIndividual::operator==(const TimeOrganizerIndividual& anotherTOI) const {
	return *uid_ == *anotherTOI.uid_;
}
bool TimeOrganizerIndividual::operator>(const TimeOrganizerIndividual& anotherTimeOrganizerIndividual) const {
	return !(*this < anotherTimeOrganizerIndividual || *this == anotherTimeOrganizerIndividual);
}
void TimeOrganizerIndividual::setEmptyIfNull(stringPtr& s) const {
	if (s == nullptr) s = emptyVals_.createEmptyString();
}
void TimeOrganizerIndividual::setEmptyIfNull(dateTimePtr& dateTime) const {
	if (dateTime == nullptr) dateTime = emptyVals_.createEmptyDateTime();
}