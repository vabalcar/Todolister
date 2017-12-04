#pragma once
#include "DateTimeFilter.h"
#include "CurrentDateTimeIntervals.h"

class CurrentDateTimeIntervalFilter {
public:
	CurrentDateTimeIntervalFilter(const string& filteredCurrentInterval) {
		filteredIntervalDic_.insert(make_pair("year", FilteredInterval::year));
		filteredIntervalDic_.insert(make_pair("month", FilteredInterval::month));
		filteredIntervalDic_.insert(make_pair("day", FilteredInterval::day));
		filteredIntervalDic_.insert(make_pair("hour", FilteredInterval::hour));
		filteredIntervalDic_.insert(make_pair("minute", FilteredInterval::minute));
		currentFilteredInterval_ = filteredIntervalDic_[filteredCurrentInterval];
		getIntervalToCompare();
	}
	CurrentDateTimeIntervalFilter(const CurrentDateTimeIntervalFilter& anotherFilter) {
		currentFilteredInterval_ = anotherFilter.currentFilteredInterval_;
		filteredIntervalDic_ = anotherFilter.filteredIntervalDic_;
		intervalToCompare_ = make_unique<DateTimeInterval>(*anotherFilter.intervalToCompare_);
	}
	bool operator()(const TimeOrganizerIndividual& toi) const {
		return intervalToCompare_->getStart() <= toi.getDateTimeForSorting() 
			&& intervalToCompare_->getEnd() >= toi.getDateTimeForSorting();
	}
	void getIntervalToCompare() {
		switch (currentFilteredInterval_) {
		case FilteredInterval::year:
			intervalToCompare_ = currentDTInts_.getCurrentYear();
			break;
		case FilteredInterval::month:
			intervalToCompare_ = currentDTInts_.getCurrentMonth();
			break;
		case FilteredInterval::day:
			intervalToCompare_ = currentDTInts_.getCurrentDay();
			break;
		case FilteredInterval::hour:
			intervalToCompare_ = currentDTInts_.getCurrentHour();
			break;
		case FilteredInterval::minute:
			intervalToCompare_ = currentDTInts_.getCurrentMinute();
			break;
		default:
			break;
		}
	}
private:
	enum FilteredInterval {
		year, month, day, hour, minute
	};
	FilteredInterval currentFilteredInterval_;
	unordered_map<string, FilteredInterval> filteredIntervalDic_;
	dtIntPtr intervalToCompare_ = nullptr;

	CurrentDateTimeIntervals currentDTInts_;
};