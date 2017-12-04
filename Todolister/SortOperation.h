#pragma once
#include "TimeOrganizerOperation.h"

class SortOperation : public TimeOrganizerOperation {
public:
	SortOperation(bool asc) : asc_(asc) {}
	toPtr process(TimeOrganizer& timeOrganizer) const;
private:
	bool asc_;
};