#pragma once
#include <unordered_map>

#include "TimeOrganizerIndividual.h"

class DateTimeFilter {
public:
	DateTimeFilter(const string& compareType, dateTimePtr dateTime) : dateTime_(move(dateTime)) {
		compareTypeDic_.insert(make_pair("since", CompareType::since));
		compareTypeDic_.insert(make_pair("matches", CompareType::matches));
		compareTypeDic_.insert(make_pair("until", CompareType::until));
		if (compareTypeDic_.find(compareType) != compareTypeDic_.end()) {
			compareType_ = compareTypeDic_[compareType];
		}
		else {
			compareType_ = CompareType::error;
		}
	}
	DateTimeFilter(const DateTimeFilter& anotherDateTime) {
		dateTime_ = make_unique<DateTime>(*anotherDateTime.dateTime_);
		compareType_ = anotherDateTime.compareType_;
		compareTypeDic_ = anotherDateTime.compareTypeDic_;
	}
	bool operator()(const TimeOrganizerIndividual& toi) const {
		switch (compareType_) {
		case CompareType::since:
			return toi.getDateTimeForSorting() >= *dateTime_;
		case CompareType::matches:
			return toi.getDateTimeForSorting() == *dateTime_;
		case CompareType::until:
			return toi.getDateTimeForSorting() <= *dateTime_;
		default:
			return false;
		}
	}
	bool isValid() { return compareType_ != CompareType::error; }
private:
	enum CompareType {
		until, matches, since, error
	};
	dateTimePtr dateTime_;
	CompareType compareType_;
	unordered_map<string, CompareType> compareTypeDic_;
};

typedef unique_ptr<DateTimeFilter> dateTimeFilterPtr;