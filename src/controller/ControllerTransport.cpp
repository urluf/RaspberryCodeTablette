/*
 * ControllerTransport.cpp
 *
 *  Created on: 11 déc. 2012
 *      Author: developpeur
 */


#include "ControllerTransport.h"

ControllerTransport::ControllerTransport(double width, double height, const char * logo, double maxW,double maxH, SShaders* Shaders ) : ControllerGeneral(width, height, logo, maxW, maxH, Shaders){

	this->model = new Model(Model::PERSO);
	mButton::reInitNbButton_Square();//met le nombre de boutons carré à zéro car la varible est de type static et que plusieurs controleurs vont l'utiliser
	createButtons();
	nbButtonSquare = mButton::getNbButton();
	this->window = new Window(width, height, logo, maxW, maxH, lButtons, Shaders, nbButtonSquare);
}

//à cleaner!!
void  ControllerTransport::createButtons(){
	this->lButtons.push_back(new mButton("Transport en commun","",SQUARE ));
	this->lButtons.push_back(new mButton("Taxi", "", SQUARE));
	this->lButtons.push_back(new mButton("Aéroport", "", SQUARE));
	this->lButtons.push_back(new mButton("Close", "", CIRCLE ));
}

void ControllerTransport::display(){
	this->window->display();
}

string ControllerTransport::setDisplay(string titleButton){
//doit changer l'affichage en fonction des touches sur lesquels on a appuyé
}

string ControllerTransport::action(double x, double y){
	return "NULL";
}

ControllerTransport::~ControllerTransport(){
	delete this->window;
}
