#ifndef _DRAWCIRCLE_H
	#define _DRAWCIRCLE_H
	
#include <GLES2/gl2.h>
#include <stddef.h>
#include <math.h>

#define DEGREES_TO_RADIANS(x) (3.14159265358979323846 * x / 180.0)

class DrawCircle{
private:
	struct vertexCircle{
		GLfloat position[3];
		GLfloat normal[3];
	};
	
	double radius;
	GLuint VCbuffer;

public:
	DrawCircle(double radius);
	void AttachAttribToData(GLuint vPos, GLuint vNorm);
	void Draw();

	~DrawCircle();
private:
	void setVertex(vertexCircle &vertex, double posX, double posY);
};

#endif
