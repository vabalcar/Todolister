#include "MergeOperation.h"

toPtr MergeOperation::process(TimeOrganizer& timeOrganizer) const {
	InsertOperation::process(timeOrganizer);
	timeOrganizer.sort(false);
	return nullptr;
}