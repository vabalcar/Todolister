#include "OutputPrinter.h"
#include "FileException.h"
#include "TimeOrganizerPrinter.h"
#include "InvalidArgumentException.h"
#include "ParseException.h"

void OutputPrinter::parseOutputDetails(const vector<string>& args, size_t& index) {
	bool parsed = false;
	for (; index < args.size(); index++) {
		if (args[index].size() != 2 || args[index][0] != '-') throw InvalidArgumentException(index);
		if (index == args.size() - 1)  throw TodolisterException("Unexpected end of arguments!");
		switch (args[index][1]) {
		case 't':
			outputTioType_ = args[++index];
			break;
		case 'f':
			outputFile_ = args[++index];
			break;
		case 'l':
			outputLayout_ = args[++index];
			break;
		case 'd':
			outputDescription_ = args[++index];
			break;
		case 'c':
			outputDelimiters_ = args[++index];
			break;
		case 'm':
			outputFormat_ = args[++index];
			break;
		default:
			--index;
			parsed = true;
			break;
		}
		if (parsed) break;
	}
}
void OutputPrinter::parseOutputFile(ofstream& ofs) const {
	if (outputFile_.empty()) return;
	ofs.open(outputFile_);
	if (!ofs.good()) {
		throw FileException("Can't open given output file!");
	}
}
void OutputPrinter::printToOutput(const TimeOrganizer& timeOrganizer) const {
	if (!hasAllInfo()) throw ParseException("output - missing information");
	ofstream ofs;
	parseOutputFile(ofs);
	
	TimeOrgranizerPrinter printer(getTOIPrinter());
	layoutPtr outputLayout = getOutputLayout();
	if (outputLayout == nullptr) throw ParseException("output - wrong layout or missing information");

	return printer.print(timeOrganizer, (ofs.is_open()) ? ofs : cout, *outputLayout, getOutputFormat());
}
void OutputPrinter::createOutputFile() const {
	printToOutput(TimeOrganizer());
}
bool OutputPrinter::outputFileExists() const {
	if (FILE *file = fopen(outputFile_.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}