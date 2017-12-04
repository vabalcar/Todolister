#pragma once
#include <memory>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef unique_ptr<string> stringPtr;

string toString(char c);

vector<string> split(const string& stringToSplit, const string& delimiters);
vector<string> preserveSplit(string& stringToSplit, const string& delimiters, set<char> criticalSequenceMarks, char charToPreserve, bool preserveCriticalSequenceMarks);

vector<int> parseInts(const string& source, const string& delimiters);

vector<int> parseInts(const string& source, const char delimiter);
string readLine(istream& in);
string readAllLines(istream& in);

void toLower(string& s);
void toUpper(string& s);