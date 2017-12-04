#pragma once
#include <iostream>

#include "Time.h"

class TimePrinter {
public:
	virtual void print(const Time& time, ostream& out) const = 0;

	virtual ~TimePrinter() = default;
};