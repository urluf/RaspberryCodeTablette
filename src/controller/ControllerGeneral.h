#ifndef _CGENERAL_H
	#define _CGENERAL_H

#include<iostream>
#include "../graphic/TaskBar.h"
#include "../graphic/Window.h"
#include "../model/Model.h"
#include <list>
#include "../GlWindow.h"
#include "../SShaders.h"
#include "../model/mButton.h"
#include "../graphic/Window.h"
#include "../EnumTypeButton.h"

class ControllerGeneral{

protected:
	Window *window;
	Model *model;
	list<mButton*> lButtons;
	double width, height, maxW, maxH;
	const char * logo;
	SShaders *Shaders;
	int nbButtonSquare;
public:
	virtual void display() = 0;
	virtual void setDisplay(double x, double y) = 0; //x, y sont les coordonnées de l'endroit de l'écran où l'on vient d'appuyer
	ControllerGeneral(double width, double height, const char * logo, double maxW,double maxH, SShaders *Shaders);
	virtual void createButtons()=0;
	virtual bool action(double x, double y)=0;
	virtual ~ControllerGeneral();
	Model* getModel();
};
#endif
