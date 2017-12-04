#include "AtrNamer.h"

const string& AtrNamer::operator[](char c) const {
	return getAtrName(c);
}
const string& AtrNamer::getAtrName(char c) const {
	return names_.at(c);
}
void AtrNamer::registerName(char c, string name) {
	names_.insert(make_pair(c, name));
}
bool AtrNamer::nameExists(char c) const {
	return names_.find(c) != names_.end();
}
const char AtrNamer::getID(const string& name) const {
	for (auto it = names_.begin(); it != names_.end(); ++it) {
		if (it->second == name) return it->first;
	}
	return 0;
}