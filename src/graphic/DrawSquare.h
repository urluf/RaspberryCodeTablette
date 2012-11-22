/*
 * DrawSquare.h
 *
 *  Created on: 22 nov. 2012
 *      Author: developpeur
 */

#ifndef DRAWSQUARE_H_
	#define DRAWSQUARE_H_


#include <GLES2/gl2.h>


class DrawSquare {

private:
struct vertexSquare{
	GLfloat position[3];
	GLfloat normal[3];
};



public:
	DrawSquare(double widht, double height);
	void AttachAttribToData(GLuint vPos, GLuint vNorm);
	void Draw();


	virtual ~DrawSquare();


private:
	void SetVertex(vertexSquare &vertex, double posX, double posY);

private:
		GLuint VBObuffer;
};
#endif /* DRAWSQUARE_H_ */
