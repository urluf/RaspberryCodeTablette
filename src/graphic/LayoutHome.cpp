#include "LayoutHome.h"

LayoutHome::LayoutHome():Layout(){
	this->lButtons.push_back(new mButton("Personnel","", SQUARE ));
	this->lButtons.push_back(new mButton("Plan","", SQUARE));
	this->lButtons.push_back(new mButton("Evenements", "", SQUARE));
	this->lButtons.push_back(new mButton("Emploi du temps", "", SQUARE));
	this->lButtons.push_back(new mButton("Transports", "", SQUARE));
	this->lButtons.push_back(new mButton("Organigramme","", SQUARE));
	this->nbButtonSquare = 6;
}

LayoutHome::~LayoutHome(){

}

void LayoutHome::update(){
	//pour home, on ne fait rien ici
}
