#pragma once
#include <sstream>

#include "StringUtils.h"

string toString(char c) {
	stringstream s;
	s << c;
	return s.str();
}
vector<string> split(const string& stringToSplit, const string& delimiters) {
	vector<char> s(stringToSplit.c_str(), stringToSplit.c_str() + stringToSplit.length() + 1);
	vector<char> d(delimiters.c_str(), delimiters.c_str() + delimiters.length() + 1);
	char * token = strtok(&s[0], &d[0]);
	vector<string> tokens;
	while (token) {
		tokens.push_back(token);
		token = strtok(NULL, &d[0]);
	}
	return tokens;
}
vector<string> preserveSplit(string& stringToSplit, const string& delimiters, set<char> criticalSequenceMarks, char charToPreserve, bool preserveCriticalSequenceMarks) {
	const char substitutiveSymbol = 26;//ascii substitutive char
	char currentCriticalSequenceMark = 0;
	for (size_t i = 0; i < stringToSplit.size(); i++) {
		if (currentCriticalSequenceMark == 0 && criticalSequenceMarks.count(stringToSplit[i]) != 0) {
			currentCriticalSequenceMark = stringToSplit[i];
			if (!preserveCriticalSequenceMarks) stringToSplit[i] = delimiters[0];
		}
		else if (currentCriticalSequenceMark != 0 && stringToSplit[i] == charToPreserve) {
			stringToSplit[i] = substitutiveSymbol;
		}
		else if (currentCriticalSequenceMark != 0 && stringToSplit[i] == currentCriticalSequenceMark) {
			currentCriticalSequenceMark = 0;
			if (!preserveCriticalSequenceMarks) stringToSplit[i] = delimiters[0];
		}
	}
	vector<string> tokens(split(stringToSplit, delimiters));
	for (size_t i = 0; i < tokens.size(); i++) {
		for (size_t j = 0; j < tokens[i].size(); j++) {
			if (tokens[i][j] == substitutiveSymbol) {
				tokens[i][j] = charToPreserve;
			}
		}
	}
	return tokens;
}
vector<int> parseInts(const string& source, const string& delimiters) {
	vector<string> tokens = split(source, delimiters);
	vector<int> ints;
	int parsedInt;
	for (size_t i = 0; i < tokens.size(); i++) {
		try {
			parsedInt = stoi(tokens[i]);
			ints.push_back(parsedInt);
		}
		catch (logic_error) {
			continue;
		}
	}
	return ints;
}
vector<int> parseInts(const string& source, const char delimiter) {
	return parseInts(source, toString(delimiter));
}
string readLine(istream& in) {
	string line;
	getline(in, line);
	return line;
}
string readAllLines(istream& in) {
	stringstream buf;
	string line;
	while (!(line = readLine(in)).empty()) {
		buf << line << ' ';
	}
	return buf.str();
}
void toLower(string& s) {
	for (size_t i = 0; i < s.size(); i++) {
		s[i] = tolower(s[i]);
	}
}
void toUpper(string& s) {
	for (size_t i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
	}
}