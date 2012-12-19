#include "ControllerGeneral.h"
#include <iostream>
using namespace std;
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

string ControllerGeneral::action(double x, double y){
	list<mButton*>::iterator it = lButtons.begin();
	string actionButton = "NULL";

	while((it!=lButtons.end())&&(actionButton == "NULL")){
		actionButton = (*it)->inTheButton(x/width, y/height);
		it++;
	}
	cout<<actionButton<<endl;
	return actionButton;
}

ControllerGeneral::~ControllerGeneral(){
	delete model;
	delete window;
}


