#include "TOOGeneralParser.h"

toopPtr TOOGeneralParser::tryParse(const vector<string>& args, size_t& index) const {
	const string& opName = args[index];
	try {
		const TOOParser& parser = tooParserRegister_[opName];
		if (index + 1 < args.size()) {
			index++;
			return parser.tryParse(args, index);
		}
		return nullptr;
	}
	catch (out_of_range&) {
		return nullptr;
	}
}