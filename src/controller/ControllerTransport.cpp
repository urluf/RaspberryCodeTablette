/*
 * ControllerTransport.cpp
 *
 *  Created on: 11 déc. 2012
 *      Author: developpeur
 */

#include "ControllerTransport.h"

ControllerTransport::ControllerTransport(double width, double height) : ControllerGeneral(width, height){

	this->model = new Model(Model::TRANSPORT);
	this->layout = new LayoutTransport();
}

string ControllerTransport::setDisplay(string titleButton){
	return "";
//doit changer l'affichage en fonction des touches sur lesquels on a appuyé
}

string ControllerTransport::action(double x, double y){
	/*faire appel à action de controleur general et récupérer le nom du bouton
	si le nom du bouton ne fait pas parti de controllerTransport alors on retourne ce que nous a renvoyé action du père
	sinon on change le numéro de la page dans le modèle et on averti les autres avec le patron observateur
	à l'aide de update, on change le layout*/
	return "NULL";
}

ControllerTransport::~ControllerTransport(){

}
