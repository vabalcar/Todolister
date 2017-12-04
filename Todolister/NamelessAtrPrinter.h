#pragma once
#include "AtrPrinter.h"

class NamelessAtrPrinter : public AtrPrinter {
public:
	void print(const string& argName, const string& argVal, ostream& out) const;
};