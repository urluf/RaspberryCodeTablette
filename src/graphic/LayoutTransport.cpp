#include "LayoutTransport.h"


LayoutTransport::LayoutTransport():Layout(){
	this->lButtons.push_back(new mButton("Transport en commun","",SQUARE ));
	this->lButtons.push_back(new mButton("Taxi", "", SQUARE));
	this->lButtons.push_back(new mButton("Aeroport", "", SQUARE));
	this->lButtons.push_back(new mButton("Close", "", CIRCLE ));
	this->nbButtonSquare = 3;
}

void LayoutTransport::update(){
	//change la valeur des boutons en fonction du numéro de la page
}


LayoutTransport::~LayoutTransport(){

}
