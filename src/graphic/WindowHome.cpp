#include "WindowHome.h"


WindowHome::WindowHome(double width, double height, const char * logo, double maxW,double maxH, list<mButton*>* lButtons, SShaders *Shaders) : Window(width, height, logo, maxW, maxH, lButtons, Shaders) {

}

void WindowHome::display(){
	Window::display();
}


WindowHome::~WindowHome(){
}



