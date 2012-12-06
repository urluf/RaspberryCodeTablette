#include "ControllerHome.h"

ControllerHome::ControllerHome(double width, double height, const char * logo, double maxW,double maxH, SShaders *Shaders) : ControllerGeneral(width, height, logo, maxW, maxH, Shaders){
	this->model = new Model();
	this->lButtons = new list<mButton*>();
	this->window = new WindowHome(width, height, logo, maxW, maxH, lButtons, Shaders);
	this->display();
}

void ControllerHome::createButtons(){

}

void ControllerHome::display(){
	this->window->display();
}

void ControllerHome::setDisplay(double x, double y){
	//doit changer l'affichage en fonctiond des touches sur lesquels on a appuyé
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
	delete this->window;
}
