#pragma once
#include "TimeOrganizerIndividual.h"

class TopFilter {
public:
	TopFilter(size_t n) : counter_(n) {}
	TopFilter(const TopFilter& anotherTopFilter) {
		counter_ = anotherTopFilter.counter_;
	}
	bool operator()(const TimeOrganizerIndividual& toi) {
		if (counter_ == 0) return false;
		--counter_;
		return true;
	}
private:
	size_t counter_;
};