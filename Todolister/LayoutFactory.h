#pragma once
#include "Layout.h"

class LayoutFactory {
public:
	virtual layoutPtr Create(const string& delimiters, const string& description) const = 0;

	virtual ~LayoutFactory() = default;
};

typedef unique_ptr<LayoutFactory> layoutFactoryPtr;