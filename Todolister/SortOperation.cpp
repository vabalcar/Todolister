#include "SortOperation.h"

toPtr SortOperation::process(TimeOrganizer& timeOrganizer) const {
	timeOrganizer.sort(asc_);
	return nullptr;
}