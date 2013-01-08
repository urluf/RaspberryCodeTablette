#ifndef _CHOME_H
	#define _CHOME_H

#include "ControllerGeneral.h"
#include "../graphic/LayoutHome.h"

using namespace std;

class ControllerHome : public ControllerGeneral{

public:
	ControllerHome(double width, double height);
	~ControllerHome();

	virtual string setDisplay(string titleButton);
	string action(double x, double y);
};
#endif

/*dans le main on fous tous les controleurs, chaque controleur aura ses propres mod�les
dans le mod�le home, on aura les coordonn�es de chaque boutons pour supprendre les clicks
� la s�lection on lance le display d'un controleur qui change la vue*/
