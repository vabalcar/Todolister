#pragma once
#include "TOOParser.h"
#include "TOOParserRegister.h"

class TOOGeneralParser : public TOOParser {
public:
	TOOGeneralParser(const TOOParserRegister& tooParserRegister) : tooParserRegister_(tooParserRegister) {}
	toopPtr tryParse(const vector<string>& args, size_t& index) const;
private:
	const TOOParserRegister& tooParserRegister_;
};