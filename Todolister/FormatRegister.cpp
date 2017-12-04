#include "FormatRegister.h"

Format& FormatRegister::operator[](const string& formatName) const {
	return *registeredFormats_.at(formatName);
}
void FormatRegister::addFormat(const string& name, formatPtr format) {
	registeredFormats_.insert(make_pair(name, move(format)));
}
bool FormatRegister::formatExists(const string& name) const {
	return registeredFormats_.find(name) != registeredFormats_.end();
}