#ifndef _WINDOW_H
#define _WINDOW_H

#include <list>
#include <string>
#include <Utility/3D/CShaderProgram.h>
#include <Utility/3D/CTexture.h>
#include <Utility/3D/CTextureQuad.h>
#include "TaskBar.h"
#include "../model/mButton.h"
#include "../SShaders.h"
#include "../EnumTypeButton.h"
#include "DrawCircle.h"
#include "DrawSquare.h"


using namespace std;

class Window{


protected:
	OpenUtility::CMat4x4<float> Pmatrix;
	TaskBar *taskBar;
	SShaders *Shaders;
	list<mButton*>	*lButtons;
	float Height;

public:
Window(double width, double height, const char * logo, double maxW,double maxH, list<mButton*>* lButtons, SShaders *Shaders);
virtual ~Window() = 0;
TaskBar* getTaskBar();
virtual void display();

};

#endif
