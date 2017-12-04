#pragma once
#include "TOIParser.h"
#include "TOIPrinter.h"

class TOIIO {
public:
	TOIIO(toiParserPtr parser, toiPrinterPtr printer) : parser_(move(parser)), printer_(move(printer)) {}
	TOIParser& getParser() { return *parser_; }
	TOIPrinter& getPrinter() { return *printer_; }
private:
	toiParserPtr parser_;
	toiPrinterPtr printer_;
};

typedef unique_ptr<TOIIO> toiIOPtr;