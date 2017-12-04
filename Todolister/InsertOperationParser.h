#pragma once
#include "TOOParser.h"
#include "TOIIORegister.h"
#include "LayoutFactoryRegister.h"
#include "FormatRegister.h"

class InsertOperationParser : public TOOParser {
public:
	InsertOperationParser(
		const TOIIORegister& toiIORegister,
		const LayoutFactoryRegister& layoutFactoryRegister, 
		const FormatRegister& formatRegiter,
		const string& defaultInputTio,
		const string& defaultInputLayout,
		const string& defaultInputFormat)
		: toiIORegister_(toiIORegister), 
		layoutFactoryRegister_(layoutFactoryRegister), 
		formatRegister_(formatRegiter),
		defaultInputTio_(defaultInputTio),
		defaultInputLayout_(defaultInputLayout),
		defaultInputFormat_(defaultInputFormat) {}
	toopPtr tryParse(const vector<string>& args, size_t& index) const;

	virtual ~InsertOperationParser() = default;
private:
	const TOIIORegister& toiIORegister_;
	const LayoutFactoryRegister& layoutFactoryRegister_;
	const FormatRegister& formatRegister_;
	const string defaultInputTio_;
	const string defaultInputLayout_;
	const string defaultInputFormat_;
};