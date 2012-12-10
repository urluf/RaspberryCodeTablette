/*
 * DrawSquare.cpp
 *
 *  Created on: 22 nov. 2012
 *      Author: developpeur
 */

#include "DrawSquare.h"
#include <stddef.h>

DrawSquare::DrawSquare(double width, double height) {
	// TODO Auto-generated constructor stub
	vertexSquare vertexArray[4];

	SetVertex(vertexArray[0], -width, height);
	SetVertex(vertexArray[1], -width, -height);
	SetVertex(vertexArray[2], width, -height);
	SetVertex(vertexArray[3], width, height);

	glGenBuffers(1,&VBObuffer);
	glBindBuffer(GL_ARRAY_BUFFER,VBObuffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertexArray),vertexArray,GL_STATIC_DRAW);
}

void DrawSquare::AttachAttribToData(GLuint vPos, GLuint vNorm){
	glBindBuffer(GL_ARRAY_BUFFER, VBObuffer);
	glVertexAttribPointer(vPos, 3, GL_FLOAT, GL_FALSE, sizeof(vertexSquare), (void*)offsetof(vertexSquare, position));
	glVertexAttribPointer(vNorm,3,GL_FLOAT,GL_FALSE,sizeof(vertexSquare),(void*)offsetof(vertexSquare,normal));
	glEnableVertexAttribArray(vPos);
	glEnableVertexAttribArray(vNorm);
}

void DrawSquare::Draw(){
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glBindBuffer(GL_ARRAY_BUFFER,0);
}

void DrawSquare::SetVertex(vertexSquare &vertex, double posX, double posY){
	vertex.position[0] = posX;
	vertex.position[1] = posY;
	vertex.position[2] = 0;
	vertex.normal[0]=0;
	vertex.normal[1]=0;
	vertex.normal[2]=1;

}



DrawSquare::~DrawSquare() {
	// TODO Auto-generated destructor stub
	glDeleteBuffers(1,&VBObuffer);
}

