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

using namespace std;

class mButton{
enum typeButton{
	CIRCLE,
	SQUARE
};

private:
	string title;
	const char* icone;
	OpenUtility::CMat4x4<float> transMatrix;
	typeButton typeB;

public:
	mButton(string title, const char* icone, OpenUtility::CMat4x4<float> transMatrix, typeButton typeB);
	~mButton();

};



#endif /* MBUTTON_H_ */
