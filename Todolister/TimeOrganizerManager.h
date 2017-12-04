#pragma once
#include "InputParser.h"
#include "OutputPrinter.h"
#include "ArgTranslator.h"

class TimeOrganizerManager {
public:
	TimeOrganizerManager(OutputPrinter& outputPrinter, const ArgTranslator& argTranslator) 
		: printer_(outputPrinter), translator_(argTranslator) {}
	void safeConfiguration(const vector<string>& args, size_t& index);
	void parseManagedFile(const vector<string>& args, size_t& index, InputParser& inputParser);
	void setOutputPrinter(OutputPrinter& outputPrinter) const;
private:
	const ArgTranslator& translator_;
	OutputPrinter& printer_;
	string lastOpenManagedFile_;

	vector<string> parseConfiguration(const string& name) const;
};