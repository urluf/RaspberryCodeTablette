#ifndef _CMain_H
	#define _CMain_H

#include<iostream>
#include "ControllerGeneral.h"
#include "ControllerHome.h"
#include "ControllerTransport.h"
#include "../GlWindow.h"
#include "../SShaders.h"


class ControllerMain{
private:
	ControllerGeneral *currentController;
	ControllerTransport *controllerTransport;
	ControllerHome *controllerHome;
	Model *modelCurrentController;

public:
	ControllerMain(double width, double height, const char * logo, double maxW,double maxH, SShaders *Shaders);
	~ControllerMain();
	void display();
	void setDisplay(string titleButton);
	bool action(double x, double y);
};
#endif

/*dans le main on fous tous les controleurs, chaque controleur aura ses propres mod�les
dans le mod�le home, on aura les coordonn�es de chaque boutons pour supprendre les clicks
� la s�lection on lance le display d'un controleur qui change la vue*/
