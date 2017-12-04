#pragma once
#include <functional>

#include "TimeOrganizerIndividual.h"
#include "DateTimeFilter.h"

class TimeOrganizer;

typedef unique_ptr<TimeOrganizer> toPtr;

class TimeOrganizer {
public:
	size_t size() const {
		return timeOrganizerIndividuals_.size();
	}
	const TimeOrganizerIndividual& operator[](size_t index) const {
		return *timeOrganizerIndividuals_[index];
	}
	void addEvent(toiPtr timeOrganizerIndividual);
	toiPtr extractFirst();
	void sort(bool asc);
	toPtr getFilteredView(function<bool(const TimeOrganizerIndividual&)>& filter) const;
private:
	vector<toiPtr> timeOrganizerIndividuals_;
};

typedef unique_ptr<function<bool(const TimeOrganizerIndividual&)>> filterPtr;