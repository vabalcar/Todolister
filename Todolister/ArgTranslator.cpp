#include "ArgTranslator.h"
 
void ArgTranslator::translate(vector<string>& args) const {
	for (size_t i = 0; i < args.size(); i++) {
		translate(args[i]);
		if (followedByArg_.count(args[i]) != 0) ++i;
	}
}
void ArgTranslator::translate(string& arg) const {
	toLower(arg);
	if (dictionary_.count(arg) == 1) {
		arg = dictionary_.at(arg);
	}
}
string ArgTranslator::inverseTranslate(const string& arg) const {
	string result = arg;
	toLower(result);
	for (auto it = dictionary_.begin(); it != dictionary_.end(); ++it) {
		if (it->second == result) return it->first;
	}
	return "";
}