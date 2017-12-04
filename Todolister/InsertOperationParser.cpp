#include "InsertOperationParser.h"
#include "InsertOperation.h"
#include "InputParser.h"

toopPtr InsertOperationParser::tryParse(const vector<string>& args, size_t& index) const {
	inputParserPtr inputParser = make_unique<InputParser>(toiIORegister_, layoutFactoryRegister_, formatRegister_,
		defaultInputTio_, defaultInputLayout_, defaultInputFormat_);
	inputParser->parseInfoFromArgs(args, index);
	return make_unique<InsertOperation>(move(inputParser));
}