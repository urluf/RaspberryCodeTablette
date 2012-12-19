#include "Coordonnee.h"
#include<stdio.h>

Coordonnee::Coordonnee(double xMin, double xMax, double yMin, double yMax){
	this->xMin = xMin;
	this->xMax = xMax;
	this->yMin = yMin;
	this->yMax = yMax;
}



double Coordonnee::getXMin(){
	return this->xMin;
}

double Coordonnee::getXMax(){
	return this->xMax;
}

double Coordonnee::getYMin(){
	return this->yMin;
}

double Coordonnee::getYMax(){
	return this->yMax;
}
