#include "TimeOrganizerManager.h"
#include "FileException.h"
#include <fstream>

void TimeOrganizerManager::safeConfiguration(const vector<string>& args, size_t& index) {
	const string& confFileName = args[index] + ".conf";
	index++;
	size_t startIndex = index;
	printer_.parseOutputDetails(args, index);
	if (!printer_.outputFileExists()) printer_.createOutputFile();
	ofstream ofs;
	ofs.open(confFileName);
	if (!ofs.good()) throw FileException("Can't safe configuration!");
	for (size_t i = startIndex; i < index; i++) {
		ofs << translator_.inverseTranslate(args[i]) << ' ';
		i++;
		if (args[i].find(' ') == 0) {
			ofs << '"' << args[i] << '"';
		}
		else {
			ofs << args[i];
		}
		ofs << endl;
	}
}
void TimeOrganizerManager::parseManagedFile(const vector<string>& args, size_t& index, InputParser& inputParser) {
	vector<string> configuration = parseConfiguration(args[index]);
	lastOpenManagedFile_ = args[index];
	size_t configurationStart = 0;
	inputParser.parseInfoFromArgs(configuration, configurationStart);
}
void TimeOrganizerManager::setOutputPrinter(OutputPrinter& outputPrinter) const {
	vector<string> configuration = parseConfiguration(lastOpenManagedFile_);
	size_t configurationStart = 0;
	outputPrinter.parseOutputDetails(configuration, configurationStart);
}
vector<string> TimeOrganizerManager::parseConfiguration(const string& name) const {
	const string& confFileName = name + ".conf";
	ifstream ifs;
	ifs.open(confFileName);
	if (!ifs.good()) throw FileException("Can't open configuration of " + name);
	vector<string> configuration = preserveSplit(readAllLines(ifs), " ", { '\'', '"' }, ' ', false);
	translator_.translate(configuration);
	return configuration;
}