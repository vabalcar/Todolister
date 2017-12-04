#include "RemoveOperation.h"
#include "NegFilter.h"

toPtr RemoveOperation::process(TimeOrganizer& timeOrganizer) const {
	NegFilter negatedFilter(*filter_);
	filterPtr fPtr = make_unique<function<bool(const TimeOrganizerIndividual&)>>(negatedFilter);
	return timeOrganizer.getFilteredView(*fPtr);
}