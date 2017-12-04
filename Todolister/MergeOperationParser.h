#pragma once
#include "InsertOperationParser.h"
#include "MergeOperation.h"

class MergeOperationParser : public InsertOperationParser {
public:
	MergeOperationParser(
		const TOIIORegister& toiIORegister,
		const LayoutFactoryRegister& layoutFactoryRegister,
		const FormatRegister& formatRegiter,
		const string& defaultInputTio,
		const string& defaultInputLayout,
		const string& defaultInputFormat)
		: InsertOperationParser(toiIORegister,
		layoutFactoryRegister,
		formatRegiter,
		defaultInputTio,
		defaultInputLayout,
		defaultInputFormat) {}
	toopPtr tryParse(const vector<string>& args, size_t& index) const;
};