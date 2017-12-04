#include "Event.h"

Event::Event(stringPtr uid, dateTimePtr dateTimeStamp, dateTimePtr startDateTime, dateTimePtr endDateTime, stringPtr name)
	: TimeOrganizerIndividual(move(uid), move(dateTimeStamp), move(name)),
	startDateTime_(move(startDateTime)), endDateTime_(move(endDateTime)) {
	setEmptyIfNull(startDateTime_);
	setEmptyIfNull(endDateTime_);
}

bool Event::operator<(const TimeOrganizerIndividual& anotherTOI) const {
	const Event& anotherEvent = static_cast<const Event&>(anotherTOI);
	if (*startDateTime_ < *anotherEvent.startDateTime_) return true;
	if (*startDateTime_ > *anotherEvent.startDateTime_) return false;
	return TimeOrganizerIndividual::operator<(anotherTOI);
}
bool Event::operator==(const TimeOrganizerIndividual& anotherTOI) const {
	const Event& anotherEvent = static_cast<const Event&>(anotherTOI);
	return *startDateTime_ == *anotherEvent.startDateTime_ && TimeOrganizerIndividual::operator==(anotherTOI);
}