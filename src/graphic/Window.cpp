#include "Window.h"
#include "../GlWindow.h"

Window::Window(double width, double height, const char * logo, double maxW,double maxH, Layout *layout, SShaders *Shaders){

	float factor=1;
	Height=2*factor*height/width;
	Width= 2*factor;
	this->taskBar = new DrawSquare ((2*factor)/2, (2*factor*height/width*.1)/2, -0.00001); //pour la hauteur le calcul est le suivant: Top-Bottom * 30%
	this->logo = new OpenUtility::CTextureQuad("../content/polytech.png", 0.23,0.2);
	this->textureFondBouton=OpenUtility::CTexture::LoadTextureFile("../content/boutonBase.png");
	this->textureIcone = OpenUtility::CTexture::LoadTextureFile("../content/icones43.png");
	this->Shaders = Shaders;
	this->layout = layout;
	this->nbButtonSquare = layout->getNbButtonSquare();
	Font40=new OpenUtility::CFontLoader("../content/arial.ttf",11);
	_3dText=new OpenUtility::C3DText(Font40);
	GL_CHECK();


	// Matrix operations
	//	MVmatrix*=OpenUtility::CMat4x4<float>().SetLookAt(0,2,3,0,0,0,0,1,0);
	//Tmatrix*=OpenUtility::CMat4x4<float>().SetTranslate(1,-3, 0);
	Pmatrix.SetFrustum(-factor,factor,-factor*height/width,factor*height/width,0.1f,1000);
	double tx=double(textureFondBouton->GetW())/textureFondBouton->GetWT();
	double ty=double(textureFondBouton->GetH())/textureFondBouton->GetHT();

	const STexture TexArrayBoutonFond[]={
			{{0.0,ty}},
			{{0,0}},
			{{tx,0}},
			{{tx,ty}}
		};

	glGenBuffers(1,&VBOtex);
	glBindBuffer(GL_ARRAY_BUFFER,VBOtex);
	glBufferData(GL_ARRAY_BUFFER,sizeof(TexArrayBoutonFond),TexArrayBoutonFond,GL_STATIC_DRAW);
	GL_CHECK();

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
	glBindBuffer(GL_ARRAY_BUFFER,VBOtex);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,textureFondBouton->GetId());
	// Set the sampler texture unit to 0
	glUniform1i(Shaders->RenderingShader["u_texId"],0);
	glVertexAttribPointer(Shaders->RenderingShader["vTexCoord"],2,GL_FLOAT,GL_FALSE,sizeof(STexture),(void*)0);
	glEnableVertexAttribArray(Shaders->RenderingShader["vTexCoord"]);
	GL_CHECK();

	taskBar->Draw();
	GL_CHECK();
	Tmatrix.SetTranslate((-Width/2)*.9,-(Height/2)*.9,0.9);
	logo->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"], Shaders->RenderingShader["vTexCoord"]);
	GL_CHECK();
	glUniformMatrix4fv(Shaders->RenderingShader["u_Nmatrix"],1,GL_FALSE,(MVmatrix*Tmatrix).GetMatrix());
	GL_CHECK();
	glUniformMatrix4fv(Shaders->RenderingShader["u_MVPmatrix"],1,GL_FALSE,(MVPmatrix*Tmatrix).GetMatrix());
	GL_CHECK();
	logo->Draw();
	list<mButton*> lButtons = this->layout->getButtons();
	this->nbButtonSquare = this->layout->getNbButtonSquare();
	
	if(!lButtons.empty())
	{
		list<OpenUtility::CMat4x4<float> > lTransIconesText;
		list<OpenUtility::CMat4x4<float> > lTransIcones;
		list<OpenUtility::CMat4x4<float> > lTransButton;  // list contenant la liste des translations à effectuer
		list<Coordonnee*> lCoord;
		double pTailleWS = 0.2; // pourcentage de la taille que l'on utilisera pour dessiner nos Boutons rectangulaires
		double pTailleHS = 0.1;
		double ptailleR = 0.05;

		/*Dans cette conditionnelle en fonction du nombre de boutons que l'on souhaite créer, on va 
 * 		enregister les translations à faire pour les boutons de formes carrés, suivi des coordonnées des points en pourcentages par rapport à l'écran par exemple xMin du carré est à 25% de la largeur total...*/
		if(this->nbButtonSquare<=3){
			lTransButton.push_back(Tmatrix.SetTranslate(0, (Height/2)*0.5,0.8999)); //tout en haut au milieu
			lCoord.push_back(new Coordonnee(0.5-pTailleWS, 0.5+pTailleWS, 0.25-pTailleHS, 0.25+pTailleHS));
			lTransIcones.push_back(Tmatrix.SetTranslate(-(Width/1.5)*0.5,(Height/1.5)*0.5,0.9));
			lTransIconesText.push_back(Tmatrix.SetTranslate(-(Width/1.5)*0.1, (Height*4.5),0.9));

			lTransButton.push_back(Tmatrix.SetTranslate(0, 0, 0.8999)); //milieu
			lCoord.push_back(new Coordonnee(0.5-pTailleWS, 0.5+pTailleWS, 0.5-pTailleHS, 0.5+pTailleHS));
			lTransIcones.push_back(Tmatrix.SetTranslate(-(Width/1.2)*0.5,(Height/1.2)*0.5,0.9));
			lTransIconesText.push_back(Tmatrix.SetTranslate(-(Width/1.5)*0.1,-(Height*0.5),0.9));


			lTransButton.push_back(Tmatrix.SetTranslate(0, -(Height/2)*0.5,0.8999));
			lCoord.push_back(new Coordonnee(0.5-pTailleWS, 0.5+pTailleWS, 0.75-pTailleHS, 0.75+pTailleHS));//coord(xMin, xMax, yMin, yMax)
			lTransIcones.push_back(Tmatrix.SetTranslate(-(Width/1.2)*0.5,-(Height/1.2)*0.5,0.9));
			lTransIconesText.push_back(Tmatrix.SetTranslate(-(Width/1.5)*0.1,-(Height*5.3),0.9));

		}
		else{
			lTransButton.push_back(Tmatrix.SetTranslate(-(Width/2)*0.5,(Height/2)*0.5,0.8999)); //en haut à gauche
			lCoord.push_back(new Coordonnee(0.25-pTailleWS, 0.25+pTailleWS, 0.25-pTailleHS, 0.25+pTailleHS));
			lTransIcones.push_back(Tmatrix.SetTranslate(-(Width/1.2)*0.5,(Height/2)*0.5,0.9));
			lTransIconesText.push_back(Tmatrix.SetTranslate(-(Width*6.2), (Height*4.5),0.9));

			lTransButton.push_back(Tmatrix.SetTranslate((Width/2)*0.5,-(Height/2)*0.5,0.8999));//en bas à droite
			lCoord.push_back(new Coordonnee(0.75-pTailleWS, 0.75+pTailleWS, 0.75-pTailleHS, 0.75+pTailleHS));
			lTransIcones.push_back(Tmatrix.SetTranslate((Width/6)*0.5,-(Height/2)*0.5,0.9));
			lTransIconesText.push_back(Tmatrix.SetTranslate((Width*3),-(Height*5.3),0.9));

			lTransButton.push_back(Tmatrix.SetTranslate((Width/2)*0.5,(Height/2)*0.5,0.8999));//en haut à droite
			lCoord.push_back(new Coordonnee(0.75-pTailleWS, 0.75+pTailleWS, 0.25-pTailleHS, 0.25+pTailleHS));
			lTransIcones.push_back(Tmatrix.SetTranslate((Width/6)*0.5,(Height/2)*0.5,0.9));
			lTransIconesText.push_back(Tmatrix.SetTranslate((Width*4),(Height*4.5),0.9));


			lTransButton.push_back(Tmatrix.SetTranslate(-(Width/2)*0.5,-(Height/2)*0.5,0.8999));//en bas à gauche
			lCoord.push_back(new Coordonnee(0.25-pTailleWS, 0.25+pTailleWS, 0.75-pTailleHS, 0.75+pTailleHS));
			lTransIcones.push_back(Tmatrix.SetTranslate(-(Width/1.2)*0.5,-(Height/2)*0.5,0.9));
			lTransIconesText.push_back(Tmatrix.SetTranslate(-(Width*5.4),-(Height*5.3),0.9));

			lTransButton.push_back(Tmatrix.SetTranslate(-(Width/2)*0.5,0,0.8999));//au milieu à gauche
			lCoord.push_back(new Coordonnee(0.25-pTailleWS, 0.25+pTailleWS, 0.5-pTailleHS, 0.5+pTailleHS));
			lTransIcones.push_back(Tmatrix.SetTranslate(-(Width/1.2)*0.5,0,0.9));
			lTransIconesText.push_back(Tmatrix.SetTranslate(-(Width*6),-(Height*0.5),0.9));

			lTransButton.push_back(Tmatrix.SetTranslate((Width/2)*0.5,0,0.8999));//au milieu à droite
			lCoord.push_back(new Coordonnee(0.75-pTailleWS, 0.75+pTailleWS, 0.5-pTailleHS, 0.5+pTailleHS));
			lTransIcones.push_back(Tmatrix.SetTranslate((Width/6)*0.5,0,0.9));
			lTransIconesText.push_back(Tmatrix.SetTranslate((Width*4.4),-(Height*0.5),0.9));
		}


		list<OpenUtility::CMat4x4<float> >::iterator itTMatrix = lTransButton.begin();
		list<Coordonnee*>::iterator itCoord = lCoord.begin();
		list<OpenUtility::CMat4x4<float> >::iterator itTMatrixIcones = lTransIcones.begin();
		for(list<mButton*>::iterator it = lButtons.begin(); it != lButtons.end(); ++it)
		{
			switch((*it)->getTypeButton()){
			case SQUARE:
			{
				(*it)->setCoord((*itCoord));

				DrawSquare *bouton = new DrawSquare(Width*pTailleWS, Height*pTailleHS);
				bouton->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);
				glBindBuffer(GL_ARRAY_BUFFER,VBOtex);
				glVertexAttribPointer(Shaders->RenderingShader["vTexCoord"],2,GL_FLOAT,GL_FALSE,sizeof(STexture),(void*)0);
				glEnableVertexAttribArray(Shaders->RenderingShader["vTexCoord"]);
				glUniformMatrix4fv(Shaders->RenderingShader["u_Nmatrix"],1,GL_FALSE,(MVmatrix*(*itTMatrix)).GetMatrix());
				GL_CHECK();
				glUniformMatrix4fv(Shaders->RenderingShader["u_MVPmatrix"],1,GL_FALSE,(MVPmatrix*(*itTMatrix)).GetMatrix());
				GL_CHECK();
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D,textureFondBouton->GetId());
				 //Set the sampler texture unit to 0
				glUniform1i(Shaders->RenderingShader["u_texId"],0);
				bouton->Draw();
				GL_CHECK();

				/** icone***********************************************************************************************/
				if(((*it)->getTitle() == "Personnel")||((*it)->getTitle() == "Plan")||((*it)->getTitle() == "Evenements")||((*it)->getTitle() == "Emploi du temps")
						||((*it)->getTitle() == "Organigramme")||((*it)->getTitle() == "Transports"))
				{

					double tx = double(textureIcone->GetW())/textureIcone->GetWT();
					double ty = double(textureIcone->GetH())/textureIcone->GetHT();

					double tx1, tx2,tx3, tx4;
					double ty1,ty2,ty3,ty4;

					if((*it)->getTitle() == "Organigramme"){
						tx1=0; ty1=ty;
						tx2=0, ty2=0;
						tx3=tx*.15; ty3=0;
						tx4=tx*.15; ty4=ty;
					}
					else if((*it)->getTitle() == "Plan"){
						tx1=tx*.50; ty1=ty;
						tx2=tx*.50, ty2=0;
						tx3=tx*.70; ty3=0;
						tx4=tx*.70; ty4=ty;
					}
					else if((*it)->getTitle() == "Evenements"){
						tx1=tx*.85; ty1=ty;
						tx2=tx*.85, ty2=0;
						tx3=tx; ty3=0;
						tx4=tx; ty4=ty;
					}
					else if((*it)->getTitle() == "Emploi du temps"){
						tx1=tx*.20; ty1=ty;
						tx2=tx*.20, ty2=0;
						tx3=tx*.35; ty3=0;
						tx4=tx*.35; ty4=ty;
					}
					else if((*it)->getTitle() == "Personnel"){
						tx1=tx*.35; ty1=ty;
						tx2=tx*.35, ty2=0;
						tx3=tx*.50; ty3=0;
						tx4=tx*.50; ty4=ty;
					}
					else if((*it)->getTitle() == "Transports"){
						tx1=tx*.70; ty1=ty;
						tx2=tx*.70, ty2=0;
						tx3=tx*.85; ty3=0;
						tx4=tx*.85; ty4=ty;
					}
					 STexture TexArrayIcone[]={
														{{tx1,ty1}},
														{{tx2,ty2}},
														{{tx3,ty3}},
														{{tx4,ty4}}
													};

					DrawSquare *icone = new DrawSquare((Width/10)*pTailleWS, (Height/2)*pTailleHS);
					icone->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);


					glGenBuffers(1,&VBOtexIcon);
					glBindBuffer(GL_ARRAY_BUFFER,VBOtexIcon);
					glBufferData(GL_ARRAY_BUFFER,sizeof(TexArrayIcone),TexArrayIcone,GL_STATIC_DRAW);
					GL_CHECK();

					glUniformMatrix4fv(Shaders->RenderingShader["u_Nmatrix"],1,GL_FALSE,(MVmatrix*(*itTMatrixIcones)).GetMatrix());
					GL_CHECK();
					glUniformMatrix4fv(Shaders->RenderingShader["u_MVPmatrix"],1,GL_FALSE,(MVPmatrix*(*itTMatrixIcones)).GetMatrix());
					GL_CHECK();
					glBindBuffer(GL_ARRAY_BUFFER,VBOtexIcon);
					glVertexAttribPointer(Shaders->RenderingShader["vTexCoord"],2,GL_FLOAT,GL_FALSE,sizeof(STexture),(void*)0);
					glEnableVertexAttribArray(Shaders->RenderingShader["vTexCoord"]);
					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE_2D,textureIcone->GetId());
					// Set the sampler texture unit to 0
					glUniform1i(Shaders->RenderingShader["u_texId"],0);
					icone->Draw();
					GL_CHECK();

					delete icone;
					glDeleteBuffers(1,&VBOtexIcon);
				}
				itTMatrixIcones++;
				itTMatrix++;
				itCoord++;
				delete bouton;

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
		list<OpenUtility::CMat4x4<float> >::iterator itTMatrixText = lTransIconesText.begin();
		OpenUtility::CMat4x4<float> matrixScale;
		matrixScale.SetScale(0.05,0.05,1);
		MVPmatrix = MVPmatrix*matrixScale;
		for(list<mButton*>::iterator it = lButtons.begin(); it != lButtons.end(); ++it)
		{

			if((*it)->getTypeButton() == SQUARE){
				_3dText->SetText((*it)->getTitle().c_str(),OpenUtility::CFontLoader::CFontEngine::EHAlignCenter,OpenUtility::CFontLoader::CFontEngine::EVAlignBaseligne);
				GL_CHECK();
				glUniformMatrix4fv(Shaders->RenderingShader["u_Nmatrix"],1,GL_FALSE,(MVmatrix*(Tmatrix.SetTranslate(.9,.9,1))).GetMatrix());
				GL_CHECK();
				glUniformMatrix4fv(Shaders->RenderingShader["u_MVPmatrix"],1,GL_FALSE,(MVPmatrix*(*itTMatrixText)).GetMatrix());
				GL_CHECK();
				_3dText->AttachAttribToData(Shaders->RenderingShader["vPos"],Shaders->RenderingShader["vNorm"],Shaders->RenderingShader["vTexCoord"]);
				_3dText->Draw();
				itTMatrixText++;
				GL_CHECK();
			}
		}
	}
}

void Window::setLayout(Layout *layout){
	this->layout = layout;
	this->nbButtonSquare = layout->getNbButtonSquare();
}

Window::~Window(){
	delete taskBar;
	delete Shaders;
	glDeleteBuffers(1,&VBOtex);
	delete textureFondBouton;
}
