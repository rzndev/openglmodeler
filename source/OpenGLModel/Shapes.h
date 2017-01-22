#pragma once

#include <gl/GL.h>
#include <gl/GLU.h>

class CShapes
{
public:
	CShapes(void);
	~CShapes(void);
	void Box(GLdouble size);
	void Sphere(GLdouble radius, GLint slices, GLint stacks);
	void doughnut(GLfloat r, GLfloat R, GLint nsides, GLint rings);
	void drawBox(GLfloat size, GLenum type);
	GLUquadricObj* quadObj;
	void initQuadObj(void);
	void drawtriangle(int i, GLfloat data[][3], int ndx[][3],
  GLenum shadeType);
	void subdivide(GLfloat* v0, GLfloat* v1, GLfloat* v2, GLenum shadeType);
	void recorditem(GLfloat* n1, GLfloat* n2, GLfloat* n3, GLenum shadeType);
	void normalize(GLfloat v[3]);
	void crossprod(GLfloat v1[3], GLfloat v2[3], GLfloat prod[3]);
	void Pyramid(GLenum shadeType);
};

