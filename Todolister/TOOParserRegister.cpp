#include "TOOParserRegister.h"

const TOOParser& TOOParserRegister::operator[](const string& name) const {
	return *registeredParsers_.at(name);
}
void TOOParserRegister::addParser(const string& name, tooParserPtr parser) {
	registeredParsers_.insert(make_pair(name, move(parser)));
}
bool TOOParserRegister::exists(const string& name) const {
	return registeredParsers_.find(name) != registeredParsers_.end();
}