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

using namespace std;

class mButton{


private:
	string title;
	const char* icone;
	OpenUtility::CMat4x4<float> transMatrix;
	typeButton typeB;

public:
	mButton(string title, const char* icone, OpenUtility::CMat4x4<float> &transMatrix, typeButton typeB);
	~mButton();
	string getTitle();
	const char* getIcone();
	OpenUtility::CMat4x4<float> getTransMatrix();
	typeButton getTypeButton();

};



#endif /* MBUTTON_H_ */
