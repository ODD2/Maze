#pragma once
#include <math.h>
#include <GL\glut.h>
#include "odMath.h"
#include "matrix_4x4.h"
#include "vec3f.h"
void odIdentify(double(&M)[4][4]);

void odMultMatrix(const matrix_4x4 & M44);

void odRotatef(double x, double y, double z);

void odTranslatef(double x, double y, double z);

void odLookAt(double eyeX, double  eyeY, double eyeZ,
	double centerX, double centerY, double centerZ,
	double upX, double upY, double upZ);

void odPerspective(double fovy, double aspect, double nearZ, double farZ);