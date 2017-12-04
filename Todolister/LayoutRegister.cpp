#include "LayoutFactoryRegister.h"

const LayoutFactory& LayoutFactoryRegister::operator[](const string& layoutName) const {
	return *registeredLayoutFactories_.at(layoutName);
}
void LayoutFactoryRegister::addLayoutFactory(const string& layoutName, layoutFactoryPtr layoutFactory) {
	registeredLayoutFactories_.insert(make_pair(layoutName, move(layoutFactory)));
}
bool LayoutFactoryRegister::layoutFactoryExists(const string& name) const {
	return registeredLayoutFactories_.find(name) != registeredLayoutFactories_.end();
}
layoutPtr LayoutFactoryRegister::createLayout(const string& layoutName, const string& delimiters, const string& description) const {
	if (registeredLayoutFactories_.count(layoutName) == 0) {
		return nullptr;
	}
	return (*this)[layoutName].Create(delimiters, description);
}