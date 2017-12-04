#pragma once
#include "TimeOrganizer.h"

class TimeOrganizerOperation {
public:
	virtual toPtr process(TimeOrganizer& timeOrganizer) const = 0;

	virtual ~TimeOrganizerOperation() = default;
};

typedef unique_ptr<TimeOrganizerOperation> toopPtr;