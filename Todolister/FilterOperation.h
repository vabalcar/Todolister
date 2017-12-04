#pragma once
#include "TimeOrganizerOperation.h"

class FilterOperation :  public TimeOrganizerOperation {
public:
	FilterOperation(filterPtr filter) : filter_(move(filter)) {}
	toPtr process(TimeOrganizer& timeOrganizer) const;

	virtual ~FilterOperation() = default;
protected:
	filterPtr filter_;
};