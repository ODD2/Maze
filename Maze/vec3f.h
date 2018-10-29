#pragma once
#include <math.h>
#include <exception>
#include "odMath.h"
#include <memory>
using namespace std;
class vec3f
{
public:
	vec3f();
	vec3f(double s1, double s2, double s3);
	~vec3f();
	double space[3];



	

	friend vec3f operator+(const vec3f& a, const vec3f& b) {
		return vec3f(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
	}

	friend vec3f operator-(const vec3f& a, const vec3f& b) {
		return vec3f(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
	}

	friend double operator*(const vec3f& a, const vec3f& b) {
		return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
	}
	
	static vec3f CrossProduct(const vec3f& a, const vec3f& b);

	static vec3f Normalize(const vec3f& a);

	vec3f& operator=(const vec3f& t) {
		/*for (int i = 0; i < 3; i++)
			space[i] = t.space[i];*/
		memcpy(space, t.space, sizeof(space));
		return *this;
	}

	double& operator[](size_t index);

	const double& operator[](size_t index) const;

};

