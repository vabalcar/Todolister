#include "SortOperationParser.h"
#include "SortOperation.h"

toopPtr SortOperationParser::tryParse(const vector<string>& args, size_t& index) const {
	bool asc = false;
	if (args[index] == "asc") { asc = true; }
	if (asc || args[index] == "desc") { return make_unique<SortOperation>(asc); }
	else { return nullptr; }
}