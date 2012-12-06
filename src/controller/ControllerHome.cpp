#include "ControllerHome.h"

ControllerHome::ControllerHome(double width, double height, const char * logo, double maxW,double maxH, SShaders *Shaders) : ControllerGeneral(width, height, logo, maxW, maxH, Shaders){
	this->model = new Model();
	this->lButtons = new list<mButton*>();
	createButtons();
	this->window = new WindowHome(width, height, logo, maxW, maxH, lButtons, Shaders);
	this->display();
}

void ControllerHome::createButtons(){
	this->lButtons->push_back(new mButton("Personnel","", OpenUtility::CMat4x4<float>().SetTranslate(1,2,0), SQUARE ));
	this->lButtons->push_back(new mButton("Plan","", OpenUtility::CMat4x4<float>().SetTranslate(2,2,0), SQUARE));
	this->lButtons->push_back(new mButton("Evenements", "",OpenUtility::CMat4x4<float>().SetTranslate(3,2,0), SQUARE));
	this->lButtons->push_back(new mButton("Emploi du temps", "", OpenUtility::CMat4x4<float>().SetTranslate(1,1,0), SQUARE));
	this->lButtons->push_back(new mButton("Transports", "", OpenUtility::CMat4x4<float>().SetTranslate(1,3,0), SQUARE));
	this->lButtons->push_back(new mButton("Organigramme","", OpenUtility::CMat4x4<float>().SetTranslate(3,1,0), SQUARE));
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
