#include "NamelessAtrParser.h"

stringPtr NamelessAtrParser::getValue(string& source) const {
	if (source.empty()) return nullptr;
	return make_unique<string>(source);
}