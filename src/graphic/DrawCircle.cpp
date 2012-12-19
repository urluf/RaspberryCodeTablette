#include "DrawCircle.h"


DrawCircle::DrawCircle(double radius){
	this->radius = radius;
	vertexCircle vertexArray[360];
	
	double posX, posY;
	
	for(int cpt = 0; cpt<360; cpt++){
		posX = this->radius * (cos(DEGREES_TO_RADIANS(cpt)));
		posY = this->radius * (sin(DEGREES_TO_RADIANS(cpt)));
		setVertex(vertexArray[cpt], posX, posY);
	}
	
	glGenBuffers(1,&VCbuffer);
	glBindBuffer(GL_ARRAY_BUFFER,VCbuffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertexArray),vertexArray,GL_STATIC_DRAW);
}

void DrawCircle::Draw(){
	glDrawArrays(GL_TRIANGLE_FAN, 0, 360);
	glBindBuffer(GL_ARRAY_BUFFER,0);
}

void DrawCircle::AttachAttribToData(GLuint vPos, GLuint vNorm){
	glBindBuffer(GL_ARRAY_BUFFER, VCbuffer);
	glVertexAttribPointer(vPos, 3, GL_FLOAT, GL_FALSE, sizeof(vertexCircle), (void*)offsetof(vertexCircle, position));
	glVertexAttribPointer(vNorm,3,GL_FLOAT,GL_FALSE,sizeof(vertexCircle),(void*)offsetof(vertexCircle,normal));
	glEnableVertexAttribArray(vPos);
	glEnableVertexAttribArray(vNorm);
}

void DrawCircle::setVertex(vertexCircle &vertex, double posX, double posY){
		vertex.position[0] = posX;
		vertex.position[1] = posY;
		vertex.position[2] = 0;
		vertex.normal[0] = 0;
		vertex.normal[1] = 0;
		vertex.normal[2] = 1;
}


DrawCircle::~DrawCircle(){
	glDeleteBuffers(1,&VCbuffer);
}


