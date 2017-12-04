#pragma once
#include <fstream>

#include "TOIIORegister.h"
#include "LayoutFactoryRegister.h"
#include "FormatRegister.h"

#include "InputParser.h"
#include "OutputPrinter.h"

#include "TimeOrganizerOperation.h"
#include "TOOGeneralParser.h"

#include "ArgTranslator.h"
#include "TimeOrganizerManager.h"

class ArgumentsProcessor {
public:
	ArgumentsProcessor(const TOOParserRegister& operationParserRegister, 
		const TOIIORegister& toiIORegister,
		const LayoutFactoryRegister& layoutFactoryRegister, 
		const FormatRegister& formatRegister, 
		const ArgTranslator& argTranslator,
		const string& defaultTio,
		const string& defaultLayout,
		const string& defaultFormat) 
		: ArgumentsProcessor(operationParserRegister, 
			toiIORegister,
			layoutFactoryRegister, 
			formatRegister,
			argTranslator,
			defaultTio, defaultTio,
			defaultLayout, defaultLayout,
			defaultFormat, defaultFormat) {}
	ArgumentsProcessor(const TOOParserRegister& operationParserRegister,
		const TOIIORegister& toiIORegister,
		const LayoutFactoryRegister& layoutFactoryRegister, 
		const FormatRegister& formatRegister,
		const ArgTranslator& argTranslator,
		const string& defaultInputTio, const string& defaultOutputTio,
		const string& defaultInputLayout, const string& defaultOutputLayout,
		const string& defaultInputFormat, const string& defaultOutputFormat)
		: operationParser_(operationParserRegister),
		argTranslator_(argTranslator),
		inputParser_(toiIORegister, layoutFactoryRegister, formatRegister,
			defaultInputTio, defaultInputLayout, defaultInputFormat),
		outputPrinter_(toiIORegister, layoutFactoryRegister, formatRegister,
			defaultOutputTio, defaultOutputLayout, defaultOutputFormat),
		confTester_(toiIORegister, layoutFactoryRegister, formatRegister,
			defaultOutputTio, defaultOutputLayout, defaultOutputFormat),
		timeOrganizerManager_(confTester_, argTranslator_) {}
	void process(vector<string>& args);
	const InputParser& getInputParser() const {
		return inputParser_;
	}
	const OutputPrinter& getOutputPrinter() {
		if (!outputSpecified_ && managedOutputSpecified_) {
			timeOrganizerManager_.setOutputPrinter(outputPrinter_);
		}
		return outputPrinter_;
	}
	const vector<toopPtr>& getOperations() const {
		return operations_; 
	}
	bool loadNothing() const {
		return loadNothing_;
	}
private:
	InputParser inputParser_;
	OutputPrinter outputPrinter_;
	OutputPrinter confTester_;
	vector<toopPtr> operations_;
	TOOGeneralParser operationParser_;
	const ArgTranslator& argTranslator_;
	TimeOrganizerManager timeOrganizerManager_;
	bool loadNothing_ = false;

	bool outputSpecified_ = false;
	bool managedOutputSpecified_ = false;
};