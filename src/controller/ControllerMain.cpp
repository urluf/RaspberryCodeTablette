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

bool ControllerMain::action(double x, double y){
	string actionButton = this->currentController->action(x, y);
	if(actionButton != "NULL"){
		this->setDisplay(actionButton);
		return true;
	}
	return false;
}

void ControllerMain::setDisplay(string titleButton){
	if(titleButton != "NULL"){
		if(titleButton == "Close")
		{
			this->currentController = controllerHome;
		}
		else if((this->currentController->getModel()->getNumPage() == 1)&&(this->currentController->getModel()->getCurrentPage()=="home")){
			if(titleButton ==  "Transports"){
				this->currentController = controllerTransport;
			}
		}
	}
}

ControllerMain::~ControllerMain(){
	delete this->currentController;
}

