#pragma once
#include "TimeOrganizerIndividual.h"

class Event : public TimeOrganizerIndividual {
public:
	static const char START_DATETIME_ID = 's';
	static const char END_DATETIME_ID = 'e';

	Event(stringPtr uid, dateTimePtr dateTimeStamp, dateTimePtr startDateTime, dateTimePtr endDateTime, stringPtr name);
	bool operator<(const TimeOrganizerIndividual& anotherTOI) const;
	bool operator==(const TimeOrganizerIndividual& anotherTOI) const;
	DateTime& getDateTimeForSorting() const {
		return getStartDateTime();
	}
	DateTime& getStartDateTime() const {
		return *startDateTime_;
	}
	DateTime& getEndDateTime() const {
		return *endDateTime_;
	}
	void setStartDateTime(dateTimePtr startDateTime) {
		startDateTime_ = move(startDateTime);
	}
	void setEndDateTime(dateTimePtr endDateTime) {
		endDateTime_ = move(endDateTime);
	}
private:
	dateTimePtr startDateTime_;
	dateTimePtr endDateTime_;
};

typedef shared_ptr<Event> eventPtr;