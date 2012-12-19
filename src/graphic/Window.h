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
#include <Template/CMat4x4.h>
#include <GLES2/gl2.h>

using namespace std;

class Window{

protected:
	OpenUtility::CMat4x4<float> Pmatrix;
	TaskBar *taskBar;
	SShaders *Shaders;
	list<mButton*>	lButtons;
	float Height, Width;
	int nbButtonSquare;

public:
Window(double width, double height, const char * logo, double maxW,double maxH, list<mButton*> lButtons, SShaders *Shaders, int nbButtonSquare);
~Window();
TaskBar* getTaskBar();
void display();

};

#endif
