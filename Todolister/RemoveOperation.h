#pragma once
#include "FilterOperation.h"

class RemoveOperation : public FilterOperation {
public:
	RemoveOperation(filterPtr filter) : FilterOperation(move(filter)) {}
	toPtr process(TimeOrganizer& timeOrganizer) const;
};