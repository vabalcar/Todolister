#include "MergeOperationParser.h"

toopPtr MergeOperationParser::tryParse(const vector<string>& args, size_t& index) const {
	toopPtr insertOpPtr = InsertOperationParser::tryParse(args, index);
	InsertOperation& insertOp = static_cast<InsertOperation&>(*insertOpPtr);
	return make_unique<MergeOperation>(move(insertOp.getInputParser()));
}