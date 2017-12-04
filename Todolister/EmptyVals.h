#pragma once
#include "DateTime.h"
#include "StringUtils.h"

class EmptyVals {
public:
	EmptyVals() : emptyDateTime_(createEmptyDateTime()), emptyString_(createEmptyString()){}
	dateTimePtr createEmptyDateTime() const;
	bool isEmptyDateTime(const DateTime& dateTime) const;
	stringPtr createEmptyString() const;
	bool isEmptyString(const string& s) const;
private:
	dateTimePtr emptyDateTime_;
	stringPtr emptyString_;
};