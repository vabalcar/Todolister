#include "TopFilterParser.h"
#include "TopFilter.h"

filterPtr TopFilterParser::tryParse(const vector<string>& args, size_t& index) const {
	TopFilter filter(stoi(args[index]));
	return make_unique<function<bool(const TimeOrganizerIndividual&)>>(filter);
}