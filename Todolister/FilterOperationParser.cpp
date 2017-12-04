#include "FilterOperationParser.h"
#include "FilterOperation.h"

toopPtr FilterOperationParser::tryParse(const vector<string>& args, size_t& index) const {
	const FilterParser& parser = filterParserRegister_[args[index]];
	if (index + 1 < args.size()) index++;
	else return nullptr;
	filterPtr filter = parser.tryParse(args, index);
	if (filter == nullptr) return nullptr;
	return make_unique<FilterOperation>(move(filter));
}