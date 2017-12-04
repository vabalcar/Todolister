#include <windows.h>//just for colored output to console

#include <sstream>

#include "EventParser.h"
#include "EventPrinter.h"
#include "TodoParser.h"
#include "TodoPrinter.h"

#include "TableLayoutFactory.h"
#include "ICalendarLayoutFactory.h"

#include "CsCz.h"
#include "EnUs.h"
#include "ICalendarFormat.h"

#include "ArgTranslator.h"
#include "ArgumentsProcessor.h"

#include "FilterParserRegister.h"
#include "CurrentDateTimeIntervalFilterParser.h"
#include "DateTimeFilterParser.h"
#include "TopFilterParser.h"

#include "TimeOrganizerOperator.h"
#include "SortOperationParser.h"
#include "FilterOperationParser.h"
#include "RemoveOperationParser.h"
#include "InsertOperationParser.h"
#include "MergeOperationParser.h"

#include "InvalidArgumentException.h"
#include "FileException.h"

enum Color {
	GREY = 8, GREEN = 10, RED = 12, WHITE = 15, DARK_GREEN = 2
};

unsigned int headlineCounter = 0;

//Windows only, it's not standardized:
void highlitedWriteLine(ostream& out, const string& line, Color color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ConsoleDefaultInfo;
	GetConsoleScreenBufferInfo(hConsole, &ConsoleDefaultInfo);
	WORD Attributes = ConsoleDefaultInfo.wAttributes;//store default console atributes
	SetConsoleTextAttribute(hConsole, color);//set green color
	out << line << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);//restore default console properties
}

//Windows only, it's not standardized:
void setConsoleTextColor(Color c) { 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}

void writeHeadline(ostream& out, const string& headline, Color color) {
	++headlineCounter;
	const char HEADLINE_SYMBOL = '+';
	stringstream h;
	h << HEADLINE_SYMBOL << " " << headlineCounter << ". " << headline << " " << HEADLINE_SYMBOL;
	stringstream s;
	for (size_t i = 0; i < h.str().length(); i++) {  s << HEADLINE_SYMBOL; }
	highlitedWriteLine(out, s.str(), color);
	highlitedWriteLine(out, h.str(), color);
	highlitedWriteLine(out, s.str(), color);
}

//Windows only, it's not standardized:
string GetAbsPath(char* relativePath) {
	char full[_MAX_PATH];
	if (_fullpath(full, relativePath, _MAX_PATH) != NULL) return full;
	else return "";
}

int main(int argc, char** argv) {
	setConsoleTextColor(Color::WHITE);
	const string HEADLINE = "Todolister";
	const string INPUT_LABEL = ">";
	vector<string> args(argv + 1, argv + argc);
	
	unordered_map<string, string> dictionary({
		{ "from", "-i" },
		{ "file", "-f" },
		{ "layout","-l" },
		{ "format", "-m" },
		{ "containing", "-t" },
		{ "delimiters", "-c" },
		{ "select", "-d" },	
		{ "do", "-p" },
		{ "to", "-o" },
		{ "register", "-r" },
		{ "load", "-l" },
		{ "end", "-q" },
		{ "q", "-q" },
		{ "script", "-s" }
	});
	set<string> followedByArg = { "-f", "-l", "-m", "-t", "-c" };
	ArgTranslator argTranslator(dictionary, followedByArg);
	
	TOIIORegister toiIORegister;
	toiIORegister.addTOIIO("event", make_unique<TOIIO>(make_unique<EventParser>(), make_unique<EventPrinter>()));
	toiIORegister.addTOIIO("todo", make_unique<TOIIO>(make_unique<TodoParser>(), make_unique<TodoPrinter>()));

	LayoutFactoryRegister layoutFactoryRegister;
	layoutFactoryRegister.addLayoutFactory("table", make_unique<TableLayoutFactory>());
	layoutFactoryRegister.addLayoutFactory("ical", make_unique<ICalendarLayoutFactory>());

	FormatRegister formatRegister;
	formatRegister.addFormat("cs-cz", make_unique<CsCz>());
	formatRegister.addFormat("en-us", make_unique<EnUs>());
	formatRegister.addFormat("ical", make_unique<ICalendarFormat>());

	FilterParserRegister filterParserRegister;
	filterParserRegister.addParser("current", make_unique<CurrentDateTimeIntervalFilterParser>());
	filterParserRegister.addParser("datetime", make_unique<DateTimeFilterParser>(formatRegister));
	filterParserRegister.addParser("top", make_unique<TopFilterParser>());

	TOOParserRegister operationParserRegister;
	operationParserRegister.addParser("sort", make_unique<SortOperationParser>());
	operationParserRegister.addParser("filter", make_unique<FilterOperationParser>(filterParserRegister));
	operationParserRegister.addParser("remove", make_unique<RemoveOperationParser>(filterParserRegister));
	operationParserRegister.addParser("insert", make_unique<InsertOperationParser>(
		toiIORegister, layoutFactoryRegister, formatRegister,
		"event", "table", "cs-cz"));
	operationParserRegister.addParser("merge", make_unique<MergeOperationParser>(
		toiIORegister, layoutFactoryRegister, formatRegister,
		"event", "table", "cs-cz"));

	bool runAgain = false;
	bool runningScript = false;
	ifstream scriptFile;
	if (args.size() == 2) {
		argTranslator.translate(args);
		if (args[0] == "-s") {
			scriptFile.open(args[1]);
			if (!scriptFile.good()) {
				highlitedWriteLine(cerr, "Script cannot be loaded!", Color::RED);
				return -1;
			}
			runAgain = true;
			runningScript = true;
		}
	}
	istream& argsIn = (scriptFile.is_open())? scriptFile : cin;
	bool headlineWriten = false;
	do {
		if (runAgain || args.size() == 0) {
			if (!headlineWriten) {
				cout << HEADLINE << " - ";
				if (runningScript) {
					cout << "running script " << GetAbsPath(&args[1][0]);
				}
				else {
					cout << "interactive mode";
				}
				cout << endl;
				headlineWriten = true;
			}
			if (!runningScript) {
				cout << INPUT_LABEL;
			}
			string line = readLine(argsIn);
			if (runningScript) {
				if (line.empty()) {
					cout << endl;
				}
				else if (line.substr(0, 2) == "**") {
					writeHeadline(cout, line.substr(2, line.size() - 2), Color::GREEN);
					continue;
				}
				else if (line.substr(0, 2) == "//") {
					highlitedWriteLine(cout, line.substr(2, line.size() - 2), Color::GREEN);
					continue;
				}
				else {
					cout << INPUT_LABEL << line << endl;
				}
			}
			args = preserveSplit(line, " ", {'\'', '"'}, ' ', false);
			runAgain = !argsIn.eof();
			if (!runAgain && args.empty()) return 0;
			if (args.empty()) continue;
		}
		ArgumentsProcessor argumentProcessor(operationParserRegister,
			toiIORegister, layoutFactoryRegister, formatRegister, argTranslator,
			"event", "table", "cs-cz");

		try {
			argumentProcessor.process(args);
			if (argumentProcessor.loadNothing()) {
				if (runAgain) continue;
				break;
			}

			TimeOrganizer timeOrganizer = argumentProcessor.getInputParser().parseInput();

			TimeOrganizerOperator timeOrganizerOperator;
			toPtr result = timeOrganizerOperator.processOperations(timeOrganizer, argumentProcessor.getOperations());
			if (result != nullptr) timeOrganizer = *result;

			setConsoleTextColor(Color::GREY);
			argumentProcessor.getOutputPrinter().printToOutput(timeOrganizer);
		}
		catch (TodolisterException& e) {
			highlitedWriteLine(cerr, e.getMessage(), Color::RED);
		}
		setConsoleTextColor(Color::WHITE);
	} while (runAgain);
}
