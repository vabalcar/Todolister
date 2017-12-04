#include "CurrentDateTimeIntervals.h"

dtIntPtr CurrentDateTimeIntervals::getCurrentYear() {
	currentDateTime_.update();
	datePtr startDate = make_unique<Date>(currentDateTime_.now()->getDate().getYear(), 1, 1);
	dateTimePtr start = make_unique<DateTime>(move(startDate), nullptr);
	datePtr endDate = make_unique<Date>(currentDateTime_.now()->getDate().getYear(), 12, 31);
	dateTimePtr end = make_unique<DateTime>(move(endDate), nullptr);
	return make_unique<DateTimeInterval>(move(start), move(end));
}
dtIntPtr CurrentDateTimeIntervals::getCurrentMonth() {
	currentDateTime_.update();
	datePtr startDate = make_unique<Date>(currentDateTime_.now()->getDate().getYear(), currentDateTime_.now()->getDate().getMonth(), 1);
	dateTimePtr start = make_unique<DateTime>(move(startDate), nullptr);
	datePtr endDate = make_unique<Date>(currentDateTime_.now()->getDate().getYear(), currentDateTime_.now()->getDate().getMonth(), 31);
	dateTimePtr end = make_unique<DateTime>(move(endDate), nullptr);
	return make_unique<DateTimeInterval>(move(start), move(end));
}
dtIntPtr CurrentDateTimeIntervals::getCurrentDay() {
	currentDateTime_.update();
	return make_unique<DateTimeInterval>(make_unique<DateTime>(*currentDateTime_.today()), 
		make_unique<DateTime>(*currentDateTime_.today()));
}
dtIntPtr CurrentDateTimeIntervals::getCurrentHour() {
	currentDateTime_.update();
	dateTimePtr start = currentDateTime_.today();
	start->setTime(make_unique<Time>(currentDateTime_.now()->getTime().getHours(), 0, 0));
	dateTimePtr end = currentDateTime_.today();
	end->setTime(make_unique<Time>(currentDateTime_.now()->getTime().getHours(), 59, 59));
	return make_unique<DateTimeInterval>(move(start), move(end));
}
dtIntPtr CurrentDateTimeIntervals::getCurrentMinute() {
	currentDateTime_.update();
	dateTimePtr start = currentDateTime_.today();
	start->setTime(make_unique<Time>(currentDateTime_.now()->getTime().getHours(), currentDateTime_.now()->getTime().getMinutes(), 0));
	dateTimePtr end = currentDateTime_.today();
	end->setTime(make_unique<Time>(currentDateTime_.now()->getTime().getHours(), currentDateTime_.now()->getTime().getMinutes(), 59));
	return make_unique<DateTimeInterval>(move(start), move(end));
}
