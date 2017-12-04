#include "InsertOperation.h"

toPtr InsertOperation::process(TimeOrganizer& timeOrganizer) const {
	TimeOrganizer toToInsert = inputParser_->parseInput();
	size_t inserts = toToInsert.size();
	for (size_t i = 0; i < inserts; i++) {
		timeOrganizer.addEvent(toToInsert.extractFirst());
	}
	return nullptr;
}