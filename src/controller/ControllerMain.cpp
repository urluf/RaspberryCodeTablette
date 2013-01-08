#include"ControllerMain.h"

ControllerMain::ControllerMain(double width, double height, const char * logo, double maxW,double maxH, SShaders *Shaders){
	this->controllerHome = new ControllerHome(width, height);
	this->controllerTransport = new ControllerTransport(width, height);
	this->currentController = this->controllerHome;
	this->window = new Window(width, height, logo, maxW, maxH, this->currentController->getLayout(), Shaders);
}

void ControllerMain::display(){
	this->window->display();
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
		this->currentController->getModel()->premierePage(); //on reinitialise pour être certain que l'on démarrera à la première page
	}
	this->window->setLayout(this->currentController->getLayout());//on change car un changement aurait pu avoir lieu à l'intérieur du currentController au niveau du layout
}

ControllerMain::~ControllerMain(){
	delete this->currentController;
	delete this->window;
}

