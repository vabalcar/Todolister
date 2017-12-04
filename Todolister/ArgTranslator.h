#pragma once
#include <unordered_map>
#include <set>

#include "StringUtils.h"

class ArgTranslator {
public:
	ArgTranslator(const unordered_map<string, string>& dictionary, const set<string>& followedByArg) 
		: dictionary_(dictionary), followedByArg_(followedByArg) {}
	void translate(vector<string>& args) const;
	void translate(string& arg) const;
	string inverseTranslate(const string& arg) const;
private:
	const unordered_map<string, string>& dictionary_;
	const set<string>& followedByArg_;
};