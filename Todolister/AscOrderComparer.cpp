#include "AscOrderComparer.h"

bool AscOrderComparer::operator()(const toiPtr& toi1, const toiPtr& toi2) {
	return *toi1 < *toi2;
}