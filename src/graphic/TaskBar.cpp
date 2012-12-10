/*
 * TaskBar.cpp
 *
 *  Created on: 3 déc. 2012
 *      Author: developpeur
 */
#include <Template/CMat4x4.h>
#include "TaskBar.h"

TaskBar::TaskBar(const char *srcImg,double maxW,double maxH, double width, double height){
	//this->logo = new CTextureQuad(*srcImg, maxW, maxH);
	this->bar = new DrawSquare(width/2, height/2);

}

void TaskBar::AttachAttribToData(GLuint vPos, GLuint vNorm){
	this->bar->AttachAttribToData(vPos,vNorm);
}

void TaskBar::Draw(){
	this->bar->Draw();
}




TaskBar::~TaskBar(){

}

void TaskBar::setBar(DrawSquare &bar){
	this->bar = &bar;
}

/*void TaskBar::setLogo(CTextureQuad &logo){
	this->logo = &logo;
}*/

void TaskBar::setTime(time_t time){
	this->time = time;
}

DrawSquare* TaskBar::getBar(){
	return (this->bar);
}

/*CTextureQuad  TaskBar::getLogo(){
	return this->logo;
}*/

time_t TaskBar::getTime(){
	return this->time;
}
