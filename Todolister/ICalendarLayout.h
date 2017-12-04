#pragma once
#include "Layout.h"
#include "StringUtils.h"
#include "ICalendarAtrParser.h"
#include "ICalendarAtrPrinter.h"

class ICalendarLayout : public Layout {
public:
	ICalendarLayout(const string& defaultOrder);
	const string getHeader(const string& toSign) const {
		return formatSign(toSign, true);
	}
	const string getFooter(const string& toSign) const {
		return formatSign(toSign, false);
	}
	const string getTOIStart(const string& toiSign) const {
		return formatSign(toiSign, true);
	}
	const string getTOIEnd(const string& toiSign) const {
		return formatSign(toiSign, false);
	}
	const string getInputTOIAtrsDelimiters() const {
		return ICAL_TOI_ATRS_DELIMITER;
	}
	const string getOutputTOIAtrsDelimiters() const {
		return ICAL_TOI_ATRS_DELIMITER;
	}
	const string getTOIAtrsOrder() const {
		return orders.at(currentObject_);
	}
	const string getTOIDelimiters() const {
		return ICAL_TOI_DELIMITER;
	}	
	bool argDelimiterAfterLastArg() const {
		return true;
	}
	string getNextTOISource(istream& in);
	const AtrParser& getAtrParser() const {
		return atrParser_;
	}
	const AtrPrinter& getAtrPrinter() const {
		return atrPrinter_;
	}
	const AtrNamer& getAtrNamer() const {
		return namer_;
	}
private:
	ICalendarAtrParser atrParser_;
	ICalendarAtrPrinter atrPrinter_;
	AtrNamer namer_;

	string currentObject_;
	unordered_map<string, string> orders;

	const string ICAL_TOI_ATRS_DELIMITER = "\n";//automatically converted to CRLF
	const string ICAL_TOI_DELIMITER = "";

	void determineOrder(istream& in);
	string formatSign(const string& sign, bool start) const {
		string formated = sign;
		toUpper(formated);
		if (start) {
			formated = "BEGIN:V" + formated;
		}
		else {
			formated = "END:V" + formated;
		}
		return formated + '\n';
	}
};