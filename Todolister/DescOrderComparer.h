#pragma once
#include "TimeOrganizerIndividual.h"

class DescOrderComparer {
public:
	bool operator()(const toiPtr& toi1, const toiPtr& toi2);
};