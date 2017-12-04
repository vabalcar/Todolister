#pragma once
#include "TimeOrganizer.h"
#include "TimeOrganizerOperation.h"

class TimeOrganizerOperator {
public:
	toPtr processOperations(TimeOrganizer& timeOrganizer, const vector<toopPtr>& operations) const;
	toPtr processOperation(TimeOrganizer& timeOrganizer, const TimeOrganizerOperation& operation) const;
};