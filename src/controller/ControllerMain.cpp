#include"ControllerMain.h"

ControllerMain::ControllerMain(double width, double height, const char * logo, double maxW,double maxH, SShaders *Shaders){
	this->controllerHome = new ControllerHome(width, height, logo, maxW, maxH, Shaders);
	this->controllerTransport = new ControllerTransport(width, height, logo, maxW, maxH, Shaders);
	this->currentController = this->controllerHome;
	modelCurrentController = this->currentController->getModel(); //si le nom de la page change, c'est que l'on devra changer le controleur courant
}

void ControllerMain::display(){
	this->currentController->display();
}

void ControllerMain::setDisplay(){
	this->currentController = controllerTransport;
	this->modelCurrentController = this->currentController->getModel();
}

ControllerMain::~ControllerMain(){
	delete this->currentController;
}

