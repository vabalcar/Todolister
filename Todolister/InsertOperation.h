#pragma once
#include "TimeOrganizerOperation.h"
#include "InputParser.h"

class InsertOperation : public TimeOrganizerOperation {
public:
	InsertOperation(inputParserPtr inputParser) : inputParser_(move(inputParser)) {}
	toPtr process(TimeOrganizer& timeOrganizer) const;
	inputParserPtr getInputParser() { return move(inputParser_); }

	virtual ~InsertOperation() = default;
protected:
	inputParserPtr inputParser_;
};