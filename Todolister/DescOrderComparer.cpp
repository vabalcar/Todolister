#include "DescOrderComparer.h"

bool DescOrderComparer::operator()(const toiPtr& toi1, const toiPtr& toi2) {
	return *toi1 > *toi2;
}