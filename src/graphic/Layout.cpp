#include "Layout.h"


Layout::Layout() : Observer() {}

Layout::~Layout(){}

int Layout::getNbButtonSquare(){
	return this->nbButtonSquare;
}

list<mButton*> Layout::getButtons(){
	return this->lButtons;
}
