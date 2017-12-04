#include "TableLayout.h"

TableLayout::TableLayout(const string& inputColumnDelimiters, const string& outputColumnDelimiters, const string& columnOrder) :
	inputColumnDelimiters_(inputColumnDelimiters), outputColumnDelimiters_(outputColumnDelimiters), columnOrder_(columnOrder) {
	for (size_t i = 0; i < columnOrder.size(); i++) {
		namer_.registerName(columnOrder[i], "");
	}
}
string TableLayout::getNextTOISource(istream& in) {
	return readLine(in);
}