/*
 * mButton.cpp
 *
 *  Created on: 5 déc. 2012
 *      Author: developpeur
 */
#include "mButton.h"

mButton::mButton(string title, const char* icone, OpenUtility::CMat4x4<float> transMatrix, typeButton typeB){
	this->title = title;
	this->icone = icone;
	this->transMatrix = transMatrix;
	this->typeB = typeB;
}






