#pragma once
#include <memory>
#include <stdarg.h>
using namespace std;
#define MATRIX_LIST true
class matrix_4x4
{
public:
	matrix_4x4();
	matrix_4x4(double * outerM);
	matrix_4x4(bool flag, ...);
	~matrix_4x4();

	static matrix_4x4 Traverse(const matrix_4x4& m);
	matrix_4x4& operator=(const matrix_4x4 & t) {
		memcpy(M, t.M, sizeof(M));
	}

	double * forMulMatrixd() {
		
	}

	double M[4][4];
	void LoadIdentity();
	
};

