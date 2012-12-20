/*
 * mButton.h
 *
 *  Created on: 5 déc. 2012
 *      Author: developpeur
 */

#ifndef MBUTTON_H_
#define MBUTTON_H_

#include<string>
#include <Template/CMat4x4.h>
#include "../EnumTypeButton.h"
#include "Coordonnee.h"

using namespace std;

class mButton{

private:
	static int nb_button_square;
	string title;
	const char* icone;
	OpenUtility::CMat4x4<float> transMatrix;
	typeButton typeB;
	Coordonnee *coord;
	
public:
	mButton(string title, const char* icone, typeButton typeB);
	~mButton();
	string getTitle();
	const char* getIcone();
	OpenUtility::CMat4x4<float> getTransMatrix();
	typeButton getTypeButton();
	static int getNbButton(){return nb_button_square;};
	static void reInitNbButton_Square(){nb_button_square = 0;}
	string inTheButton(double x, double y);
	void setCoord(Coordonnee *coord);
};



#endif /* MBUTTON_H_ */
