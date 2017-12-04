#pragma once
#include "DateTime.h"

class CurrentDateTime {
public:
	CurrentDateTime() {
		update();
	}
	void update();
	dateTimePtr today() const;
	dateTimePtr now() { return make_unique<DateTime>(*currentDateTime_); }
private:
	dateTimePtr currentDateTime_;
};