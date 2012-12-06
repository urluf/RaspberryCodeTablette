#include "Window.h"

Window::Window(double width, double height, const char * logo, double maxW,double maxH, list<mButton*>* lButtons, SShaders *Shaders){

	this->taskBar = new TaskBar("../content/polytech.png",0.5,0.5, 10, (height/width)*0.60); //pour la hauteur le calcul est le suivant: Top-Bottom * 30%
	this->Shaders = Shaders;
	this->lButtons = lButtons;
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


	//affichage des boutons
	for(list<mButton*>::iterator it = lButtons->begin(); it != lButtons->end(); ++it)
	{
		switch((*it)->getTypeButton()){
			case SQUARE:
			{
				DrawSquare *square = new DrawSquare(0.5, 0.5);
				square->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);
				glUniformMatrix4fv(Shaders->RenderingShader["u_trans"],1,GL_FALSE, ((*it)->getTransMatrix()).GetMatrix());
				square->Draw();
				delete square;
				break;
			}
			case CIRCLE:
			{
				DrawCircle *circle = new DrawCircle(0.5);
				circle->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);
				glUniformMatrix4fv(Shaders->RenderingShader["u_trans"],1,GL_FALSE, ((*it)->getTransMatrix()).GetMatrix());
				circle->Draw();
				delete circle;
				break;
			}
		}
	}
}

Window::~Window(){
	delete taskBar;
}
