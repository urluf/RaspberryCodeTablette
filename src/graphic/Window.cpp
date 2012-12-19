#include "Window.h"
#include "../GlWindow.h"

Window::Window(double width, double height, const char * logo, double maxW,double maxH, list<mButton*> lButtons, SShaders *Shaders, int nbButtonSquare){

	float factor=1;
	Height=2*factor*height/width;
	Width= 2*factor;
	this->taskBar = new TaskBar("../content/polytech.png",0.5,0.5, 2*factor, 2*factor*height/width*.1); //pour la hauteur le calcul est le suivant: Top-Bottom * 30%
	this->Shaders = Shaders;
	this->lButtons = lButtons;
	this->nbButtonSquare = nbButtonSquare;
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

	if(!lButtons.empty())
	{
		list<OpenUtility::CMat4x4<float> > lTransButton;  // list contenant la liste des translations à effectuer
		list<Coordonnee*> lCoord;
		double pTailleWS = 0.2; // pourcentage de la taille que l'on utilisera pour dessiner nos Boutons rectangulaires
		double pTailleHS = 0.1;
		double ptailleR = 0.05;
		/*Dans cette conditionnelle en fonction du nombre de boutons que l'on souhaite créer, on va 
 * 		enregister les translations à faire pour les boutons de formes carrés, suivi des coordonnées des points en pourcentages par rapport à l'écran par exemple xMin du carré est à 25% de la largeur total...*/
		if(this->nbButtonSquare<=3){
			lTransButton.push_back(Tmatrix.SetTranslate(0, (Height/2)*0.5,0.9)); //tout en haut au milieu
			lCoord.push_back(new Coordonnee(0.5-pTailleWS, 0.5+pTailleWS, 0.75-pTailleHS, 0.75+pTailleHS));//coord(xMin, xMax, yMin, yMax)
			lTransButton.push_back(Tmatrix.SetTranslate(0, 0, 0.9)); //milieu
			lCoord.push_back(new Coordonnee(0.5-pTailleWS, 0.5+pTailleWS, 0.5-pTailleHS, 0.5+pTailleHS));
			lTransButton.push_back(Tmatrix.SetTranslate(0, -(Height/2)*0.5,0.9));
			lCoord.push_back(new Coordonnee(0.5-pTailleWS, 0.5+pTailleWS, 0.25-pTailleHS, 0.25+pTailleHS));
		}
		else{
			lTransButton.push_back(Tmatrix.SetTranslate(-(Width/2)*0.5,(Height/2)*0.5,0.9)); //tout en haut au milieu
			lCoord.push_back(new Coordonnee(0.25-pTailleWS, 0.25+pTailleWS, 0.75-pTailleHS, 0.75+pTailleHS));
			lTransButton.push_back(Tmatrix.SetTranslate((Width/2)*0.5,-(Height/2)*0.5,0.9));
			lCoord.push_back(new Coordonnee(0.75-pTailleWS, 0.75+pTailleWS, 0.25-pTailleHS, 0.25+pTailleHS));
			lTransButton.push_back(Tmatrix.SetTranslate((Width/2)*0.5,(Height/2)*0.5,0.9));
			lCoord.push_back(new Coordonnee(0.75-pTailleWS, 0.75+pTailleWS, 0.75-pTailleHS, 0.75+pTailleHS));
			lTransButton.push_back(Tmatrix.SetTranslate(-(Width/2)*0.5,-(Height/2)*0.5,0.9));
			lCoord.push_back(new Coordonnee(0.25-pTailleWS, 0.25+pTailleWS, 0.25-pTailleHS, 0.25+pTailleHS));
			lTransButton.push_back(Tmatrix.SetTranslate(-(Width/2)*0.5,0,0.9));//ok
			lCoord.push_back(new Coordonnee(0.25-pTailleWS, 0.25+pTailleWS, 0.5-pTailleHS, 0.5+pTailleHS));
			lTransButton.push_back(Tmatrix.SetTranslate((Width/2)*0.5,0,0.9));//ok
			lCoord.push_back(new Coordonnee(0.75-pTailleWS, 0.75+pTailleWS, 0.5-pTailleHS, 0.5+pTailleHS));
		}


		list<OpenUtility::CMat4x4<float> >::iterator itTMatrix = lTransButton.begin();
		list<Coordonnee*>::iterator itCoord = lCoord.begin();
		for(list<mButton*>::iterator it = lButtons.begin(); it != lButtons.end(); ++it)
		{
			switch((*it)->getTypeButton()){
			case SQUARE:
			{
				(*it)->setCoord((*itCoord));
				DrawSquare *square = new DrawSquare(Width*pTailleWS, Height*pTailleHS);
				square->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);
				glUniformMatrix4fv(Shaders->RenderingShader["u_Nmatrix"],1,GL_FALSE,(MVmatrix*(*itTMatrix)).GetMatrix());
				GL_CHECK();
				glUniformMatrix4fv(Shaders->RenderingShader["u_MVPmatrix"],1,GL_FALSE,(MVPmatrix*(*itTMatrix)).GetMatrix());
				GL_CHECK();
				square->Draw();
				itTMatrix++;
				itCoord++;
				delete square;
				break;
			}
			case CIRCLE:
			{


				DrawCircle *circle = new DrawCircle(Height*ptailleR);
				circle->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);

				if((*it)->getTitle() == "Close"){
					glUniformMatrix4fv(Shaders->RenderingShader["u_Nmatrix"],1,GL_FALSE,(MVmatrix*(Tmatrix.SetTranslate((Width/2)*0.9, (Height/2)*0.9, 0.9))).GetMatrix());
					GL_CHECK();
					glUniformMatrix4fv(Shaders->RenderingShader["u_MVPmatrix"],1,GL_FALSE,(MVPmatrix*(Tmatrix.SetTranslate((Width/2)*0.9, (Height/2)*0.9, 0.9))).GetMatrix());
					GL_CHECK();
					(*it)->setCoord(new Coordonnee((0.9-((Width*ptailleR)/Height)), (0.9+((Width*ptailleR)/Height)), 0.1-ptailleR, 0.1+ptailleR));
				}
				else{
					glUniformMatrix4fv(Shaders->RenderingShader["u_Nmatrix"],1,GL_FALSE,(MVmatrix*(Tmatrix.SetTranslate(-(Width/2)*.9, (Height/2)*0.9, 0.9))).GetMatrix());
					GL_CHECK();
					glUniformMatrix4fv(Shaders->RenderingShader["u_MVPmatrix"],1,GL_FALSE,(MVPmatrix*(Tmatrix.SetTranslate(-(Width/2)*0.9, (Height/2)*0.9, 0.9))).GetMatrix());
					GL_CHECK();
					(*it)->setCoord(new Coordonnee((0.1-((Width*ptailleR)/Height)), (0.1+((Width*ptailleR)/Height)), 0.1-ptailleR, 0.1+ptailleR));
				}

				GL_CHECK();
				circle->Draw();
				itCoord++;
				delete circle;
				break;
			}
			}
		}
	}
}

Window::~Window(){
	delete taskBar;
	delete Shaders;
}
