#include "CurrentDateTimeIntervalFilterParser.h"
#include "CurrentDateTimeIntervalFilter.h"

filterPtr CurrentDateTimeIntervalFilterParser::tryParse(const vector<string>& args, size_t& index) const {
	CurrentDateTimeIntervalFilter filter(args[index]);
	return make_unique<function<bool(const TimeOrganizerIndividual&)>>(filter);
}