#pragma once
#include "TimeOrganizerIndividual.h"

class AscOrderComparer {
public:
	bool operator()(const toiPtr& toi1, const toiPtr& toi2);
};