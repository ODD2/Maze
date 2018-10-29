#include "vec3f.h"



vec3f::vec3f()
{
}

vec3f::vec3f(double s0, double s1, double s2) {
	space[0] = s0;
	space[1] = s1;
	space[2] = s2;
}

vec3f::~vec3f()
{
}


double& vec3f::operator[](size_t index) {
	return space[index];
}

const double& vec3f::operator[](size_t index) const {
	return space[index];
}

vec3f vec3f::CrossProduct(const vec3f& a, const vec3f& b) {
	return vec3f(
		a[1] * b[2] - b[1] * a[2],
		a[2] * b[0] - b[2] * a[0],
		a[0] * b[1] - b[0] * a[1]
	);
}

vec3f vec3f::Normalize(const vec3f& a) {
	double denom = pow( pow(a[0], 2) + pow(a[1], 2) + pow(a[2], 2),0.5);
	if (dEqual(denom, 0)) {
		throw exception("Error! denom == 0");
	}
	return vec3f(a[0] / denom, a[1] / denom, a[2] / denom);
}

