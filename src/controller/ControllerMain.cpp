#include"ControllerMain.h"

ControllerMain::ControllerMain(double width, double height, const char * logo, double maxW,double maxH, SShaders *Shaders){
	this->currentController =  new ControllerHome(width, height, logo, maxW, maxH, Shaders);
	modelCurrentController = this->currentController->getModel(); //si le nom de la page change, c'est que l'on devra changer le controleur courant
}

void ControllerMain::display(){
	this->currentController->display();
}

ControllerMain::~ControllerMain(){
	delete this->currentController;
}

