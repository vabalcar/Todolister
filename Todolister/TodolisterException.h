#pragma once
#include "StringUtils.h"

class TodolisterException {
public:
	TodolisterException(const string& message) : message_(message) {}
	const string& getMessage() { return message_; }
private:
	string message_;
};