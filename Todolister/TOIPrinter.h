#pragma once
#include "TimeOrganizerIndividual.h"
#include "DateTimePrinter.h"
#include "Layout.h"

class TOIPrinter {
public:
	static const string EMPTY_FIELD_MARK;

	virtual string getTOISign() const = 0;
	virtual string getTOSign() const = 0;
	void print(const TimeOrganizerIndividual& toi, ostream& out, const Layout& layout, const Format& format);

	virtual ~TOIPrinter() = default;
protected:
	DateTimePrinter dateTimePrinter;

	virtual bool print(const TimeOrganizerIndividual& toi, char atrToPrintId, ostream& out, const Layout& layout, const Format& format);
	void printAtr(const char& atrId, const string& atrVal, ostream& out, const Layout& layout);
	void printDateTimeAtr(const char& atrId, const DateTime& atrVal, ostream& out, const Layout& layout, const Format& format);
private:
	EmptyVals emptyVals_;
	bool printingLast_ = false;
};

typedef unique_ptr<TOIPrinter> toiPrinterPtr;