#pragma once
#include "TodolisterException.h"

class InvalidArgumentException : public TodolisterException {
public:
	InvalidArgumentException(size_t index) : TodolisterException("Error while processing argument at " + to_string(index)) {}
};