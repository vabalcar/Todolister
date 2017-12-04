#pragma once
#include <fstream>

#include "TOIIORegister.h"
#include "LayoutFactoryRegister.h"
#include "FormatRegister.h"
#include "ParseException.h"

class OutputPrinter {
public:
	OutputPrinter(const TOIIORegister& toiIORegister,
		const LayoutFactoryRegister& layoutFactoryRegister,
		const FormatRegister& formatRegister,
		const string& defaultOutputTio,
		const string& defaultOutputLayout,
		const string& defaultOutputFormat)
		: toiIORegister_(toiIORegister),
		layoutFactoryRegister_(layoutFactoryRegister),
		formatRegister_(formatRegister),
		outputTioType_(defaultOutputTio),
		outputLayout_(defaultOutputLayout),
		outputFormat_(defaultOutputFormat) {}
	void parseOutputDetails(const vector<string>& args, size_t& index);
	void printToOutput(const TimeOrganizer& timeOrganizer) const;
	bool outputFileExists() const;
	void createOutputFile() const;
	void resetOut() { outputFile_ = ""; }
private:
	string outputFile_;
	string outputDelimiters_;
	string outputDescription_;
	const TOIIORegister& toiIORegister_;
	string outputTioType_;
	const LayoutFactoryRegister& layoutFactoryRegister_;
	string outputLayout_;
	const FormatRegister& formatRegister_;
	string outputFormat_;

	void parseOutputFile(ofstream& ofs) const;
	TOIPrinter& getTOIPrinter() const {
		if (!toiIORegister_.toiIOExists(outputTioType_)) {
			throw ParseException("output - wrong toi");
		}
		return toiIORegister_[outputTioType_].getPrinter(); 
	}
	layoutPtr getOutputLayout() const {
		return layoutFactoryRegister_.createLayout(outputLayout_, outputDelimiters_, outputDescription_);
	}
	const Format& getOutputFormat() const {
		if (!formatRegister_.formatExists(outputFormat_)) throw ParseException("output - wrong format");
		return formatRegister_[outputFormat_]; 
	}
	bool hasAllInfo() const {
		return  !outputTioType_.empty()
			&& !outputLayout_.empty()
			&& !outputFormat_.empty();
	}
};