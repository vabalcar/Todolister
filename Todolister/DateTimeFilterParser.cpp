#include "DateTimeFilterParser.h"
#include "DateTimeFilter.h"

filterPtr DateTimeFilterParser::tryParse(const vector<string>& args, size_t& index) const {
	if (index + 1 >= args.size()) return nullptr;
	dateTimePtr parsedDateTime = dateTimeParser_.tryParse(args[index + 1]);
	if (parsedDateTime == nullptr) return nullptr;
	DateTimeFilter filter(args[index++], move(parsedDateTime));
	if (!filter.isValid()) return nullptr;
	return make_unique<function<bool(const TimeOrganizerIndividual&)>>(filter);
}