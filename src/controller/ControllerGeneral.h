#ifndef _CGENERAL_H
	#define _CGENERAL_H

#include<iostream>
#include "../graphic/TaskBar.h"
#include "../model/Model.h"
#include <list>
#include "../GlWindow.h"
#include "../graphic/Layout.h"

class ControllerGeneral{

protected:
	Model *model;
	Layout *layout;
	double width, height;
public:
	virtual string setDisplay(string titleButton) = 0;//indique le nom du bouton sur lequel on vient de cliquer
	ControllerGeneral(double width, double height);
	string action(double x, double y);
	virtual ~ControllerGeneral();
	Model* getModel();
	Layout* getLayout();
};
#endif
