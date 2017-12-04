#include "FilterOperation.h"

toPtr FilterOperation::process(TimeOrganizer& timeOrganizer) const {
	return timeOrganizer.getFilteredView(*filter_);
}