#include "TOIIORegister.h"

TOIIO& TOIIORegister::operator[](const string& toiIOName) const {
	return *registeredTOIIOs_.at(toiIOName);//todo
}
void TOIIORegister::addTOIIO(const string& name, toiIOPtr toi) {
	registeredTOIIOs_.insert(make_pair(name, move(toi)));
}
bool TOIIORegister::toiIOExists(const string& name) const {
	return registeredTOIIOs_.find(name) != registeredTOIIOs_.end();
}