#include "FilterParserRegister.h"

const FilterParser& FilterParserRegister::operator[](const string& name) const {
	return *registeredParsers_.at(name);
}
void FilterParserRegister::addParser(const string& name, filterParserPtr parser) {
	registeredParsers_.insert(make_pair(name, move(parser)));
}
bool FilterParserRegister::exists(const string& name) const {
	return registeredParsers_.find(name) != registeredParsers_.end();
}