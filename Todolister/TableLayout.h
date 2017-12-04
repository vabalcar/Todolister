#pragma once
#include "Layout.h"
#include "NamelessAtrParser.h"
#include "NamelessAtrPrinter.h"

class TableLayout : public Layout {
public:
	TableLayout(const string& inputColumnDelimiters, const string& outputColumnDelimiters, const string& columnOrder);
	TableLayout(const string& columnDelimiters, const string& columnOrder) : TableLayout(columnDelimiters, columnDelimiters, columnOrder) {}
	const string getHeader(const string& toSign) const {
		return "";
	}
	const string getFooter(const string& toSign) const {
		return "";
	}
	const string getTOIStart(const string& toiSign) const {
		return "";
	}
	const string getTOIEnd(const string& toiSign) const {
		return "";
	}
	const string getInputTOIAtrsDelimiters() const {
		return inputColumnDelimiters_;
	}
	const string getOutputTOIAtrsDelimiters() const {
		return outputColumnDelimiters_;
	}
	const string getTOIAtrsOrder() const {
		return columnOrder_;
	}
	const string getTOIDelimiters() const {
		return ROW_DELIMITER;
	}
	bool argDelimiterAfterLastArg() const {
		return false;
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
	NamelessAtrParser atrParser_;
	NamelessAtrPrinter atrPrinter_;
	AtrNamer namer_;

	string inputColumnDelimiters_;
	string outputColumnDelimiters_;
	string columnOrder_;

	const string ROW_DELIMITER = "\n";
};