#include "matrix_4x4.h"



matrix_4x4::matrix_4x4()
{
	memset(M, 0.0, sizeof(double) * 4 * 4);
}

matrix_4x4::matrix_4x4(double * outerM) {
	memcpy(M, outerM, sizeof(M));
}

matrix_4x4::matrix_4x4(bool flag, ...) {
	if (flag) {
		va_list vl;
		va_start(vl, flag);
		for (int i = 0; i< 4; i++) {
			for (int j = 0; j < 4; j++) {
				M[i][j] = va_arg(vl, double);
			}
		}
		va_end(vl);
	}
}

matrix_4x4::~matrix_4x4()
{
}

void matrix_4x4::LoadIdentity() {
	memset(M, 0.0, 8 * 4 * 4);
	for (int i = 0; i < 4; i++) {
		M[i][i] = 1;
	}
}

matrix_4x4 matrix_4x4::Traverse(const matrix_4x4& m) {
	matrix_4x4 ret;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ret.M[i][j] = m.M[j][i];
		}
	}
	return ret;
}