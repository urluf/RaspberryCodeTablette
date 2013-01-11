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
#include "Layout.h"
using namespace std;

class Window{

	struct STexture
	{
		GLfloat coord[2];
	};

protected:
	OpenUtility::CMat4x4<float> Pmatrix;
	DrawSquare *taskBar;
	CTextureQuad *logo;
	SShaders *Shaders;
	Layout *layout;
	float Height, Width;
	int nbButtonSquare;
	GLuint VBOtex;
	GLuint VBOtexIcon;
	CTexture *textureFondBouton;
	CTexture *textureIcone;


public:
Window(double width, double height, const char * logo, double maxW,double maxH, Layout *layout, SShaders *Shaders);
~Window();
void display();
void setLayout(Layout *layout);
STexture* fillTexIcon(string title);
};

#endif
