#include "InputParser.h"
#include "FileException.h"
#include "TimeOrganizerParser.h"
#include "InsertOperation.h"
#include "InvalidArgumentException.h"
#include "ParseException.h"

void InputParser::parseInfoFromArgs(const vector<string>& args, size_t& index) {
	bool parsed = false;
	for (; index < args.size(); index++) {
		if (args[index].size() != 2 || args[index][0] != '-') throw InvalidArgumentException(index);
		if (index == args.size() - 1)  throw TodolisterException("Unexpected end of arguments!");
		switch (args[index][1]) {
		case 't':
			storeFileAtr(inputTioTypes_, args[++index]);
			break;
		case 'f':
			storeFileName(args[++index]);
			break;
		case 'l':
			storeFileAtr(inputLayouts_, args[++index]);
			break;
		case 'd':
			storeFileAtr(inputDescriptions_, args[++index]);
			break;
		case 'c':
			storeFileAtr(inputDelimiters_, args[++index]);
			break;
		case 'm':
			storeFileAtr(inputFormats_, args[++index]);
			break;
		default:
			--index;
			parsed = true;
			break;
		}
		if (parsed) break;
	}
}
void InputParser::storeInfo(const string& file, const string& description, const string& delimiters) {
	storeFileName(file);
	storeFileAtr(inputDescriptions_, description);
	storeFileAtr(inputDelimiters_, delimiters);
}
TimeOrganizer InputParser::parseInput() const {
	if (!hasAllInfo()) throw ParseException("input - missing information");
	ifstream ifs;
	if (files_.size() > 0) {
		openFileStream(files_[0], ifs);
	}
	TimeOrganizerParser parser(getTOIParser(0));
	layoutPtr inputLayout = getInputLayout(0);
	
	if (inputLayout == nullptr) throw ParseException("input - wrong layout or missing information");
	TimeOrganizer result = parser.tryParse((ifs.is_open()) ? ifs : cin, *inputLayout, getInputFormat(0));
	
	for (size_t i = 1; i < files_.size(); i++) {
		inputParserPtr parser = make_unique<InputParser>(toiIORegister_, layoutFactoryRegister_, formatRegister_,
			getFileAtr(inputTioTypes_, i), getFileAtr(inputLayouts_, i), getFileAtr(inputFormats_, i));
		parser->storeInfo(files_[i], getFileAtr(inputDescriptions_, i), getFileAtr(inputDelimiters_, i));
		
		InsertOperation insertOp(move(parser));
		insertOp.process(result);
	}
	return result;
}
void InputParser::storeFileName(const string& fileName) {
	files_.push_back(fileName);
	++fileCounter;
}
void InputParser::storeFileAtr(vector<string>& storage, const string& value) {
	if (storage.size() >= fileCounter) {
		if (storage.size() == 0) {
			storage.push_back(value);
		}
		else {
			storage[storage.size() - 1] = value;
		}
	}
	else {
		while (storage.size() < fileCounter - 1) {
			if (storage.size() == 0) {
				storage.push_back(value);
			}
			else {
				storage.push_back(storage[storage.size() - 1]);
			}
		}
		storage.push_back(value);
	}
}
const string& InputParser::getFileAtr(const vector<string>& storage, size_t fileIndex) const {
	if (storage.size() == 0) return NOTHING;
	if (fileIndex >= storage.size()) return storage[storage.size() - 1];
	else return storage[fileIndex];
}
istream& InputParser::openFileStream(const string& file, ifstream& ifs) const {
	ifs.open(file);
	if (!ifs.good()) throw FileException("Can't open given input file!");
	return ifs;
}