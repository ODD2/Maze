#include "odTools.h"
#include <math.h>
#define __PI 3.1415926
void odIdentify(double(&M)[4][4]) {
	//Reset M
	memset(M, 0.0, 4 * 4 * 8);
	for (int i = 0; i < 4; i++) {
		M[i][i] = 1.0;
	}
}

void odMultMatrix(const matrix_4x4 & M44) {
	glMultMatrixd((double*)matrix_4x4::Traverse(M44).M);
}

void odMultMatrix(double (&M)[4][4]) {
	for(int i = 0 ; i< 4 ; i++){
		for (int j = 0; j < 4; j++) {
			double tmp = M[i][j];
			M[i][j] = M[j][i];
			M[j][i] = tmp;
		}
	}
	glMultMatrixd((double*)M);
}

void odRotatef(double angle,double x, double y, double z) {
	 double M[4][4] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	};
	
}


void  odTranslatef(double x, double y, double z){
	double M[4][4] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		x, y, z, 1.0
	};

	M[3][0] = x; M[3][1] = y; M[3][2] = z;
	glMultMatrixd((double*)M);
}

void odLookAt(double eyeX,double  eyeY,double eyeZ,
			  double centerX, double centerY, double centerZ,
			  double upX, double upY, double upZ) {

	double M[4][4] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	};

	vec3f up(upX, upY, upZ);
	vec3f w; w[0] = eyeX - centerX; w[1] = eyeY - centerY; w[2] = eyeZ - centerZ;
	w = vec3f::Normalize(w);
	vec3f u = vec3f::CrossProduct(up,w);
	u = vec3f::Normalize(u);
	vec3f v = vec3f::CrossProduct(w,u);
	v = vec3f::Normalize(v);
	for (int i = 0; i < 3; i++)
		M[0][i] = u[i];
	for (int i = 0; i < 3; i++)
		M[1][i] = v[i];
	for (int i = 0; i < 3; i++)
		M[2][i] = w[i];

	odMultMatrix(M);
	odTranslatef(-eyeX, -eyeY, -eyeZ);
}


void odPerspective(double fovy, double aspect, double nearZ, double farZ) {
	double f = cos((fovy / 2)*__PI / 180) / sin((fovy / 2)*__PI / 180);
	double M[4][4] = {
		f / aspect,			0.0,								0.0,								 0.0,
		0.0,				  f,							    0.0,								 0.0,
		0.0,	    		0.0,	(farZ + nearZ) / (nearZ - farZ),								  -1,
		0.0,				0.0,  (2 * farZ*nearZ) / (nearZ - farZ),								 0.0
	};
	//glMultMatrixd((double *)M);
	odMultMatrix(M);
}