#include "ControllerGeneral.h"
#include <iostream>
using namespace std;



ControllerGeneral::ControllerGeneral(double width, double height){
	this->width = width;
	this->height=height;
}


Model* ControllerGeneral::getModel(){
	return this->model;
}

Layout* ControllerGeneral::getLayout(){
	return this->layout;
}

string ControllerGeneral::action(double x, double y){
	list<mButton*> lButtons = this->layout->getButtons();

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
	delete layout;
}


