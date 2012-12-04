/*
 * TaskBar.h
 *
 *  Created on: 3 déc. 2012
 *      Author: developpeur
 */



#ifndef TASKBAR_H_
#define TASKBAR_H_

#include "DrawSquare.h"
#include <time.h>


class TaskBar{

private:
	//CTextureQuad logo;
	time_t time;
	DrawSquare *bar;

public:
	TaskBar(const char *srcImg,double maxW,double maxH, double width, double height);
	~TaskBar();
	void AttachAttribToData(GLuint vPos, GLuint vNorm);
	void Draw();
	void setBar(DrawSquare &bar);
	//void setLogo(CTextureQuad logo);
	void setTime(time_t time);
	DrawSquare* getBar();
	//CTextureQuad getLogo();
	time_t getTime();
};



#endif /* TASKBAR_H_ */
