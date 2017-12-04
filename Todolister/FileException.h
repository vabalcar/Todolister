#pragma once
#include "TodolisterException.h"

class FileException : public TodolisterException {
public:
	FileException(const string& message) : TodolisterException(message) {}
};