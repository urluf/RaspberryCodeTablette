#ifndef _CHOME_H
	#define _CHOME_H

#include<iostream>
#include<list>
#include "ControllerGeneral.h"
#include "../model/mButton.h"
#include "../graphic/WindowHome.h"
#include "../EnumTypeButton.h"

using namespace std;

class ControllerHome : public ControllerGeneral{

public:
	ControllerHome(double width, double height, const char * logo, double maxW,double maxH, SShaders* Shaders );
	~ControllerHome();

	virtual void display();
	virtual void setDisplay(double x, double y);

private:
	void createButtons();
};
#endif

/*dans le main on fous tous les controleurs, chaque controleur aura ses propres mod�les
dans le mod�le home, on aura les coordonn�es de chaque boutons pour supprendre les clicks
� la s�lection on lance le display d'un controleur qui change la vue*/
