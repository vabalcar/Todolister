#pragma once
#include "DateTime.h"
#include "StringUtils.h"
#include "EmptyVals.h"

class TimeOrganizerIndividual {
public:
	static const char UID_ID = 'u';
	static const char DATETIME_STAMP_ID = 'c';
	static const char NAME_ID = 'n';

	TimeOrganizerIndividual(stringPtr uid, dateTimePtr dateTimeStamp, stringPtr name);
	virtual bool operator<(const TimeOrganizerIndividual& anotherTimeOrganizerIndividual) const;
	virtual bool operator==(const TimeOrganizerIndividual& anotherEvent) const;
	bool operator>(const TimeOrganizerIndividual& anotherTimeOrganizerIndividual) const;
	virtual DateTime& getDateTimeForSorting() const {
		return getDateTimeStamp();
	}
	string& getUid() const {
		return *uid_;
	}
	DateTime& getDateTimeStamp() const {
		return *dateTimeStamp_;
	}
	string& getName() const {
		return *name_;
	}
	void setUid(const string& uid) {
		uid_ = make_unique<string>(uid);
	}
	void setDateTimeStamp(dateTimePtr dateTimeStamp) {
		dateTimeStamp_ = move(dateTimeStamp);
	}
	void setName(string name) {
		name_ = make_unique<string>(name);
	}
	
	virtual ~TimeOrganizerIndividual() = default;
protected:
	stringPtr uid_;
	dateTimePtr dateTimeStamp_;
	stringPtr name_;
	EmptyVals emptyVals_;

	void setEmptyIfNull(stringPtr& s) const;
	void setEmptyIfNull(dateTimePtr& dateTime) const;
};

typedef shared_ptr<TimeOrganizerIndividual> toiPtr;