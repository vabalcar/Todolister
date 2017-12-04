#pragma once
#include "TimeOrganizer.h"

class NegFilter {
public:
	NegFilter(const function<bool(const TimeOrganizerIndividual&)>& filter) : filter_(filter) {}
	bool operator() (const TimeOrganizerIndividual& toi) { return !filter_(toi); }
private:
	const function<bool(const TimeOrganizerIndividual&)>& filter_;
};