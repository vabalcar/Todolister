#pragma once
#include "TodolisterException.h"

class ParseException : public TodolisterException {
public:
	ParseException(const string& message) : TodolisterException("Error while parsing " + message) {}
};