#include "TimeOrganizerOperator.h"

toPtr TimeOrganizerOperator::processOperations(TimeOrganizer& timeOrganizer, const vector<toopPtr>& operations) const {
	toPtr result = nullptr;
	for (size_t i = 0; i < operations.size(); i++) {
		if (result == nullptr) {
			result = processOperation(timeOrganizer, *operations[i]);
		}
		else {
			toPtr tmpRes = processOperation(*result, *operations[i]);
			if (tmpRes != nullptr) {
				result = move(tmpRes);
			}
		}
	}
	return result;
}
toPtr TimeOrganizerOperator::processOperation(TimeOrganizer& timeOrganizer, const TimeOrganizerOperation& operation) const {
	return operation.process(timeOrganizer);
}