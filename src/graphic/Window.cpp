#include "Window.h"
#include "../GlWindow.h"

Window::Window(double width, double height, const char * logo, double maxW,double maxH, list<mButton*>* lButtons, SShaders *Shaders){

	float factor=1;
	Height=2*factor*height/width;
	this->taskBar = new TaskBar("../content/polytech.png",0.5,0.5, 2*factor, 2*factor*height/width*.1); //pour la hauteur le calcul est le suivant: Top-Bottom * 30%
	this->Shaders = Shaders;
	this->lButtons = lButtons;
	// Matrix operations
//	MVmatrix*=OpenUtility::CMat4x4<float>().SetLookAt(0,2,3,0,0,0,0,1,0);
	//Tmatrix*=OpenUtility::CMat4x4<float>().SetTranslate(1,-3, 0);
	Pmatrix.SetFrustum(-factor,factor,-factor*height/width,factor*height/width,0.1f,1000);

}

TaskBar* Window::getTaskBar(){
	return this->taskBar;
}

void Window::display(){
	OpenUtility::CMat4x4<float> MVmatrix,MVPmatrix,Tmatrix;

	MVmatrix.SetLookAt(0,0,1,0,0,0,0,1,0);
	MVPmatrix=Pmatrix*MVmatrix;

	Tmatrix.SetTranslate(0,-(Height/2)*.9,0.9);
	GL_CHECK();
	taskBar->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);
	GL_CHECK();
	glUniformMatrix4fv(Shaders->RenderingShader["u_Nmatrix"],1,GL_FALSE,(MVmatrix*Tmatrix).GetMatrix());
	GL_CHECK();
	glUniformMatrix4fv(Shaders->RenderingShader["u_MVPmatrix"],1,GL_FALSE,(MVPmatrix*Tmatrix).GetMatrix());
	GL_CHECK();
	taskBar->Draw();
	GL_CHECK();

/*
	//affichage des boutons
	for(list<mButton*>::iterator it = lButtons->begin(); it != lButtons->end(); ++it)
	{
		switch((*it)->getTypeButton()){
			case SQUARE:
			{
				DrawSquare *square = new DrawSquare(0.5, 0.5);
				square->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);
//				glUniformMatrix4fv(Shaders->RenderingShader["u_trans"],1,GL_FALSE, ((*it)->getTransMatrix()).GetMatrix());
				square->Draw();
				delete square;
				break;
			}
			case CIRCLE:
			{
				DrawCircle *circle = new DrawCircle(0.5);
				circle->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);
//				glUniformMatrix4fv(Shaders->RenderingShader["u_trans"],1,GL_FALSE, ((*it)->getTransMatrix()).GetMatrix());
				circle->Draw();
				delete circle;
				break;
			}
		}
	}*/
}

Window::~Window(){
	delete taskBar;
}
