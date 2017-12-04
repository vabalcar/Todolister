#pragma once
#include "AtrParser.h"
#include "AtrPrinter.h"
#include "AtrNamer.h"

class Layout {
public:
	virtual const string getHeader(const string& toSign) const = 0;
	virtual const string getFooter(const string& toSign) const = 0;

	virtual const string getTOIStart(const string& toiSign) const = 0;
	virtual const string getTOIEnd(const string& toiSign) const = 0;
	virtual const string getInputTOIAtrsDelimiters() const = 0;
	virtual const string getOutputTOIAtrsDelimiters() const = 0;
	virtual const string getTOIAtrsOrder() const = 0;
	
	virtual const string getTOIDelimiters() const = 0;
	virtual bool argDelimiterAfterLastArg() const = 0;

	virtual string getNextTOISource(istream& in) = 0;
	
	virtual const AtrParser& getAtrParser() const = 0;
	virtual const AtrPrinter& getAtrPrinter() const = 0;
	virtual const AtrNamer& getAtrNamer() const = 0;

	virtual ~Layout() = default;
};

typedef unique_ptr<Layout> layoutPtr;