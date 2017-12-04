#pragma once
#include <unordered_map>

#include "LayoutFactory.h"

class LayoutFactoryRegister {
public:
	const LayoutFactory& operator[](const string& layoutName) const;
	void addLayoutFactory(const string& layoutName, layoutFactoryPtr layoutFactory);
	bool layoutFactoryExists(const string& name) const;
	layoutPtr createLayout(const string& layoutName, const string& delimiters, const string& description) const;
private:
	unordered_map<string, layoutFactoryPtr> registeredLayoutFactories_;
};