#ifndef _WINDOWHOME_H
	#define _WINDOWHOME_H

#include "Window.h"	
#include <Template/CMat4x4.h>
#include <GLES2/gl2.h>

class WindowHome : public Window{

public:
WindowHome(double width, double height, const char * logo, double maxW,double maxH, list<mButton*>* lButtons, SShaders *Shaders);
~WindowHome();
virtual void display();
};

#endif
