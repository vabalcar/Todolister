#pragma once
#include "LayoutFactory.h"
#include "ICalendarLayout.h"

class ICalendarLayoutFactory : public LayoutFactory {
public:
	layoutPtr Create(const string& delimiters, const string& description) const {
		return make_unique<ICalendarLayout>(description);
	}
};