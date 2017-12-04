#pragma once
#include "LayoutFactory.h"
#include "TableLayout.h"

class TableLayoutFactory : public LayoutFactory {
public:
	layoutPtr Create(const string& delimiters, const string& description) const {
		if (delimiters.empty() || description.empty()) return nullptr;
		return make_unique<TableLayout>(delimiters, description);
	}
};