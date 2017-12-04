#pragma once
#include "InsertOperation.h"

class MergeOperation : public InsertOperation {
public:
	MergeOperation(inputParserPtr inputParser) : InsertOperation(move(inputParser)) {}
	toPtr process(TimeOrganizer& timeOrganizer) const;
};