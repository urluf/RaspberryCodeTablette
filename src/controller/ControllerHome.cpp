#include "ControllerHome.h"

ControllerHome::ControllerHome(double width, double height) : ControllerGeneral(width, height){
	this->model = new Model();
	this->layout = new LayoutHome();
}

string ControllerHome::setDisplay(string titleButton){
	//doit changer l'affichage en fonctiond des touches sur lesquels on a appuyé
	return "";
}

/*ControllerGeneral ControllerHome::setDisplay(double x, double y){
	//change la fen�tre en fonction du point d'appui
	int typeModule = window.getModuleSelect(x,y);

	switch (typeModule){
	case 1:
		return new ControllerEDT();
	case 2: 
		return new ControllerOrga();
	case 3: 
		return new ControllerPersonnel();
	case 3:
		return new ControllerPlan();
	case 4: 
		return new ControllerTransport();
	case 5:
		return new ControllerEvnmt;
	default:
		return null;
	}
}*/

ControllerHome::~ControllerHome(){
}
