#include "ControllerHome.h"

ControllerHome::ControllerHome(double width, double height, const char * logo, double maxW,double maxH, SShaders *Shaders) : ControllerGeneral(width, height, logo, maxW, maxH, Shaders){
	this->model = new Model();
	mButton::reInitNbButton_Square();//met le nombre de boutons carré à zéro car la varible est de type static et que plusieurs controleurs vont l'utiliser
	createButtons();
	this->nbButtonSquare = mButton::getNbButton();
	this->window = new Window(width, height, logo, maxW, maxH, lButtons, Shaders, nbButtonSquare);
}

//à cleaner!!
//créer une classe coordonnée dans laquelle on mettra les coordonnées des points calculés à l'aide des translations
void ControllerHome::createButtons(){
	this->lButtons.push_back(new mButton("Personnel","", SQUARE ));
	this->lButtons.push_back(new mButton("Plan","", SQUARE));
	this->lButtons.push_back(new mButton("Evenements", "", SQUARE));
	this->lButtons.push_back(new mButton("Emploi du temps", "", SQUARE));
	this->lButtons.push_back(new mButton("Transports", "", SQUARE));
	this->lButtons.push_back(new mButton("Organigramme","", SQUARE));
}

void ControllerHome::display(){
	this->window->display();
}

string ControllerHome::setDisplay(string titleButton){
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
	delete this->model;
}
