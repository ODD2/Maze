#include "odMath.h"

bool dEqual(double a, double b) {
	if (fabs(a - b) < Entrophy) {
		return true;
	}
	return false;
}
bool dLarger(double a, double b) {
	if (fabs(a - b) < Entrophy) {
		return false;
	}
	else if (a > b) {
		return true;
	}
	return false;
}
bool dSmaller(double a, double b) {
	if (fabs(a - b) < Entrophy) {
		return false;
	}
	else if (a < b) {
		return true;
	}
	return false;
}
bool dSE(double a, double b) {
	return dEqual(a, b) || dSmaller(a, b);
}
bool dLE(double a, double b) {
	return dEqual(a, b) || dLarger(a, b);
}


void dZeroArray(double * a, size_t v) {
}