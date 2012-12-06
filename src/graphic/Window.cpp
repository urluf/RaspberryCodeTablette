#include "Window.h"

Window::Window(double width, double height, const char * logo, double maxW,double maxH, list<mButton*>* lButtons, SShaders *Shaders){

	this->taskBar = new TaskBar("../content/polytech.png",0.5,0.5, 10, (height/width)*0.60); //pour la hauteur le calcul est le suivant: Top-Bottom * 30%
	this->Shaders = Shaders;
}

TaskBar* Window::getTaskBar(){
	return this->taskBar;
}

void Window::display(){
	OpenUtility::CMat4x4<float> Tmatrix;
	taskBar->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);
	Tmatrix*=OpenUtility::CMat4x4<float>().SetTranslate(1,-3, 0);
	glUniformMatrix4fv(Shaders->RenderingShader["u_trans"],1,GL_FALSE, (Tmatrix.GetMatrix()));
	taskBar->Draw();
}

Window::~Window(){
	delete taskBar;
}
