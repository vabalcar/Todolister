#include "Todo.h"

Todo::Todo(stringPtr uid, dateTimePtr dateTimeStamp, dateTimePtr dueDateTime, stringPtr name)
	: TimeOrganizerIndividual(move(uid), move(dateTimeStamp), move(name)), dueDateTime_(move(dueDateTime)) {
	setEmptyIfNull(dueDateTime_);
}

bool Todo::operator<(const Todo& anotherTodo) const {
	if (*dueDateTime_ < *anotherTodo.dueDateTime_) return true;
	if (*dueDateTime_ > *anotherTodo.dueDateTime_) return false;
	return TimeOrganizerIndividual::operator<(anotherTodo);
}
bool Todo::operator==(const Todo& anotherTodo) const {
	return *dueDateTime_ == *anotherTodo.dueDateTime_ && TimeOrganizerIndividual::operator==(anotherTodo);
}