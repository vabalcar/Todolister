#pragma once
#include <string>

using namespace std;

class AtrPrinter {
public:
	virtual void print(const string& argName, const string& argVal, ostream& out) const = 0;

	virtual ~AtrPrinter() = default;
};