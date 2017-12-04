#pragma once
#include "TimeOrganizerIndividual.h"

class Todo : public TimeOrganizerIndividual {
public:
	static const char DUE_DATETIME_ID = 'd';

	Todo(stringPtr uid, dateTimePtr dateTimeStamp, dateTimePtr dueDateTime, stringPtr name);
	bool operator<(const Todo& anotherTodo) const;
	bool operator==(const Todo& anotherTodo) const;
	DateTime& getDateTimeForSorting() const {
		return getDueDate();
	}
	DateTime& getDueDate() const {
		return *dueDateTime_;
	}
	void setDueDateTime(dateTimePtr dueDateTime) {
		dueDateTime_ = move(dueDateTime);
	}
private:
	dateTimePtr dueDateTime_;
};

typedef shared_ptr<Todo> todoPtr;