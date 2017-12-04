#pragma once
#include <fstream>

#include "TOIIORegister.h"
#include "LayoutFactoryRegister.h"
#include "FormatRegister.h"
#include "ParseException.h"

class InputParser {
public:
	InputParser(const TOIIORegister& toiIORegister,
		const LayoutFactoryRegister& layoutFactoryRegister,
		const FormatRegister& formatRegister,
		const string& defaultInputTio,
		const string& defaultInputLayout,
		const string& defaultInputFormat)
		: toiIORegister_(toiIORegister),
		layoutFactoryRegister_(layoutFactoryRegister),
		formatRegister_(formatRegister) {
		inputTioTypes_.push_back(defaultInputTio);
		inputLayouts_.push_back(defaultInputLayout);
		inputFormats_.push_back(defaultInputFormat);
	}
	void parseInfoFromArgs(const vector<string>& args, size_t& index);
	void storeInfo(const string& file, const string& description, const string& delimiters);
	TimeOrganizer parseInput() const;
private:
	size_t fileCounter = 0;
	const TOIIORegister& toiIORegister_;
	const LayoutFactoryRegister& layoutFactoryRegister_;
	const FormatRegister& formatRegister_;
	vector<string> files_;
	vector<string> inputDelimiters_;
	vector<string> inputDescriptions_;
	vector<string> inputTioTypes_;
	vector<string> inputLayouts_;
	vector<string> inputFormats_;
	const string NOTHING = "";
	
	void storeFileName(const string& fileName);
	void storeFileAtr(vector<string>& storage, const string& value);
	const string& getFileAtr(const vector<string>& storage, size_t fileIndex) const;

	istream& openFileStream(const string& file, ifstream& ifs) const;
	TOIParser& getTOIParser(size_t index) const {
		string toiIORegName = getFileAtr(inputTioTypes_, index);
		if (!toiIORegister_.toiIOExists(toiIORegName)) {
			throw ParseException("input - wrong toi");
		}
		return toiIORegister_[toiIORegName].getParser();
	}
	layoutPtr getInputLayout(size_t index) const { 
		return layoutFactoryRegister_.createLayout(getFileAtr(inputLayouts_, index), 
			getFileAtr(inputDelimiters_, index),
			getFileAtr(inputDescriptions_, index));
	}
	const Format& getInputFormat(size_t index) const {
		if (!formatRegister_.formatExists(getFileAtr(inputFormats_, index))) throw ParseException("input - wrong format");
		return formatRegister_[getFileAtr(inputFormats_, index)];
	}
	bool hasAllInfo() const {
		return !inputTioTypes_.empty() 
			&& !inputLayouts_.empty()
			&& !inputFormats_.empty();
	}
};

typedef unique_ptr<InputParser> inputParserPtr;