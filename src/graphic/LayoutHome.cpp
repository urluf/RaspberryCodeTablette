#include "LayoutHome.h"

LayoutHome::LayoutHome():Layout(){
	this->lButtons.push_back(new mButton("Personnel","../content/boutonPersonnel.png", SQUARE ));
	this->lButtons.push_back(new mButton("Plan","../content/boutonPlan.png", SQUARE));
	this->lButtons.push_back(new mButton("Evenements", "../content/boutonEvenements.png", SQUARE));
	this->lButtons.push_back(new mButton("Emploi du temps", "../content/boutonEDT.png", SQUARE));
	this->lButtons.push_back(new mButton("Transports", "../content/boutonTransport.png", SQUARE));
	this->lButtons.push_back(new mButton("Organigramme","../content/boutonOrganigramme.png", SQUARE));
	this->nbButtonSquare = 4;
}

LayoutHome::~LayoutHome(){

}

void LayoutHome::update(){
	//pour home, on ne fait rien ici
}
