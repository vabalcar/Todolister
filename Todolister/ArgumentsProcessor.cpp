#include "ArgumentsProcessor.h"
#include "InvalidArgumentException.h"
#include "ParseException.h"

void ArgumentsProcessor::process(vector<string>& args) {
	loadNothing_ = false;
	argTranslator_.translate(args);
	size_t nameIndex;
	for (size_t i = 0; i < args.size(); i++) {
		toopPtr op;
		if (args[i].size() != 2 || args[i][0] != '-') throw InvalidArgumentException(i);
		if (i == args.size() - 1 && args[i][1] != 'q') throw TodolisterException("Unexpected end of arguments!");
		switch (args[i][1]) {
		case 'i':
			inputParser_.parseInfoFromArgs(args, ++i);
			break;
		case 'o':
			if (managedOutputSpecified_) timeOrganizerManager_.setOutputPrinter(outputPrinter_);
			if (args[i + 1] == "console") {
				outputPrinter_.resetOut();
				++i;
			}
			if (i != args.size() - 1) outputPrinter_.parseOutputDetails(args, ++i);
			outputSpecified_ = true;
			break;
		case 'r':
			nameIndex = ++i;
			timeOrganizerManager_.safeConfiguration(args, i);
			if (i == args.size()) {
				loadNothing_ = true;
				break;
			}
			timeOrganizerManager_.parseManagedFile(args, nameIndex, inputParser_);
			managedOutputSpecified_ = true;
			break;
		case 'l':
			timeOrganizerManager_.parseManagedFile(args, ++i, inputParser_);
			managedOutputSpecified_ = true;
			inputParser_.parseInfoFromArgs(args, ++i);
			break;
		case 'p':
			op = operationParser_.tryParse(args, ++i);
			if (op != nullptr) {
				operations_.push_back(move(op));
			}
			else {
				throw ParseException("operation");
			}
			break;
		case 'q':
			exit(0);
			break;
		default:
			throw InvalidArgumentException(i);
			break;
		}
	}
}