#include "ControllerGeneral.h"

ControllerGeneral::ControllerGeneral(double width, double height, const char * logo, double maxW,double maxH, SShaders *Shaders){
	this->width = width;
	this->height=height;
	this->logo=logo;
	this->maxW=maxW;
	this->maxH=maxH;
	this->Shaders = Shaders;
}


Model* ControllerGeneral::getModel(){
	return this->model;
}

ControllerGeneral::~ControllerGeneral(){
	delete model;
	delete window;
}


