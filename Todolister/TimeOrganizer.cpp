#include <algorithm>

#include "TimeOrganizer.h"
#include "AscOrderComparer.h"
#include "DescOrderComparer.h"

void TimeOrganizer::addEvent(toiPtr timeOrganizerIndividual) {
	timeOrganizerIndividuals_.push_back(timeOrganizerIndividual);
}
toiPtr TimeOrganizer::extractFirst() {
	if (timeOrganizerIndividuals_.size() == 0) return nullptr;
	toiPtr first = move(timeOrganizerIndividuals_.front());
	timeOrganizerIndividuals_.erase(timeOrganizerIndividuals_.begin());
	return first;
}
void TimeOrganizer::sort(bool asc) {
	if (asc) {
		std::sort(timeOrganizerIndividuals_.begin(), timeOrganizerIndividuals_.end(), AscOrderComparer());
	}
	else {
		std::sort(timeOrganizerIndividuals_.begin(), timeOrganizerIndividuals_.end(), DescOrderComparer());
	}
}
toPtr TimeOrganizer::getFilteredView(function<bool(const TimeOrganizerIndividual&)>& filter) const {
	toPtr filteredView = make_unique<TimeOrganizer>();
	for (size_t i = 0; i < timeOrganizerIndividuals_.size(); i++) {
		if (filter((*this)[i])) {
			filteredView->addEvent(timeOrganizerIndividuals_[i]);
		}
	}
	return filteredView;
}