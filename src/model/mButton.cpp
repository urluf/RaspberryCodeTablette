/*
 * mButton.cpp
 *
 *  Created on: 5 déc. 2012
 *      Author: developpeur
 */
#include "mButton.h"

int mButton::nb_button_square = 0;

mButton::mButton(string title, const char* icone, OpenUtility::CMat4x4<float> &transMatrix, typeButton typeB){
	this->title = title;
	this->icone = icone;
	this->typeB = typeB;

	if(this->typeB == SQUARE){
		mButton::nb_button_square++;
	}
	
	this->coord = NULL;
}

void mButton::setCoord(Coordonnee *coord){

	this->coord = coord;

}

string mButton::getTitle(){
	return this->title;
}

const char* mButton::getIcone(){
	return this->icone;
}

typeButton mButton::getTypeButton(){
	return this->typeB;
}

OpenUtility::CMat4x4<float> mButton::getTransMatrix(){
	return this->transMatrix;
}

bool mButton::inTheButton(double x, double y){
	printf("%f, %f, %f, %f\n", x, y, this->coord->getXMin(), this->coord->getXMax());
	if(typeB == SQUARE){
		if((x>=this->coord->getXMin())&&(x<=this->coord->getXMax())){
			if((y>=this->coord->getYMin())&&(y<=this->coord->getYMax())){
				return true;
			}
		}
	}
	return false;
}

mButton::~mButton(){
	delete coord;
}
