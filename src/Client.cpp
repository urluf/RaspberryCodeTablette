//coding: utf-8
#include "Client.h"
#include <iostream>
#include <Template/CMat4x4.h>

Client::Client() :
	nbIndexes(0),
	Shaders(NULL),
	//TexQuad(NULL)
	//square(NULL)
	circle(NULL),
	taskBar(NULL)

{
}

Client::~Client()
{
	delete(Shaders);
}

void Client::Start()
{
	OpenWindow();
}

void Client::Init()
{
//	clock_gettime(CLOCK_MONOTONIC,&_debTime);
	double height = static_cast<double>(GetHeight());
	double width = static_cast<double>(GetWidth());
	Shaders=new SShaders;
	if (!Shaders->ShaderVertex.LoadFile("../shader/rendering.vert"))
		std::cout << "-----------------------------------\nErreur vertex shader :\n" << Shaders->ShaderVertex.GetLog() << std::endl << "--------------------------" << std::endl;
	if (!Shaders->ShaderFragment.LoadFile("../shader/rendering.frag"))
		std::cout << "-----------------------------------\nErreur fragment shader :\n" << Shaders->ShaderFragment.GetLog() << std::endl << "--------------------------" << std::endl;
	if (!Shaders->RenderingShader.LinkProgram())
		std::cout << "-----------------------------------\nErreur shader program :\n" << Shaders->RenderingShader.GetLog() << std::endl << "--------------------------" << std::endl;

	Shaders->RenderingShader.UseProgram();

	// Set background color and clear buffers
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Initialisation of the opengl state
	glEnable(GL_DEPTH_TEST);

	// Data to visualize
	//TexQuad=new CTextureQuad("../content/polytech.png",20,20);
	//square =  new DrawSquare(8, 4);
	circle = new DrawCircle(0.5);


	GL_CHECK();

	cMain = new ControllerMain(GetWidth(),GetHeight(),"../content/polytech.png", 0.5,0.5, Shaders);

	//cadre de la fenêtre utilisé pour l'affichage
	glViewport(0,0,GetWidth(),GetHeight());
	GL_CHECK();
}

void Client::Uninit()
{
//	delete TexQuad;
	delete circle;
	//delete square;
    delete cMain;
	glDeleteBuffers(1,&VBOtex);
	glDeleteBuffers(1,&VBOindex);
}

void Client::PreRender()
{
	struct timespec curTime;
//	clock_gettime(CLOCK_MONOTONIC,&curTime);

	curTime=DiffTime(_debTime,curTime);
	if (curTime.tv_sec>10)
	{
//		CloseWindow();
	}
}

void Client::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glActiveTexture(GL_TEXTURE0);
	//glUniform1i(Shaders->RenderingShader["u_texId"],0);
	//TexQuad->AttachAttribToData(Shaders->RenderingShader["vPos"],Shaders->RenderingShader["vNorm"],Shaders->RenderingShader["vTexCoord"]);




	OpenUtility::CMat4x4<float> Tmatrix, T1matrix;
	for (int i=0;i<1;i++){
		cMain->display();
		GL_CHECK();
/*		circle->AttachAttribToData(Shaders->RenderingShader["vPos"], Shaders->RenderingShader["vNorm"]);
		T1matrix*=OpenUtility::CMat4x4<float>().SetTranslate(1,2,0);
		glUniformMatrix4fv(Shaders->RenderingShader["u_trans"],1,GL_FALSE, (T1matrix.GetMatrix()));
		circle->Draw();
		GL_CHECK();*/

	}
		//TexQuad->Draw();

}

timespec Client::DiffTime(timespec start,timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}

void Client::OnKeyDown(unsigned int id,int keyCode)
{
	std::cout << "Press (id #" << id << ") : " << keyCode << std::endl;
	if (keyCode==KEY_Q)
		CloseWindow();
}

void Client::OnPeripheralAdd(unsigned int id,const char *name,EPeriphType type)
{
	std::cout << "Nouveau périphérique (id=" << id << " type=" << GlWindow::GetPeripheralTypeName(type) << ") : " << name << std::endl;
}

void Client::OnPeripheralRemove(unsigned int id,const char *name)
{
	std::cout << "Déconnexion de (id=" << id << ") : " << name << std::endl;
}

void Client::OnMouseMove(unsigned int id,double x,double y)
{
	std::cout << "Mouse (id #" << id << ") move : x=" << x << " ; y=" << y << std::endl;
}

void Client::On6axisChange(unsigned int id,double x,double y,double z,double rx,double ry,double rz)
{
	std::cout << "6axis (id #" << id << ") move : x=" << x << " ; y=" << y << " ; z=" << z << " ; rx=" << rx << " ; ry=" << ry << " ; rz=" << rz << std::endl;
}

void Client::OnWheelChange(unsigned int id,double x,double y)
{
	std::cout << "Wheel (id #" << id << ") : x=" << x << " ; y=" << y << std::endl;
}

void Client::OnHatChange(unsigned int id,int sub,double x,double y)
{
	std::cout << "Hat (id #" << id << ") ID #" << sub << " : x=" << x << " ; y=" << y << std::endl;
}

void Client::OnTiltChange(unsigned int id,double x,double y)
{
	std::cout << "Tilt (id #" << id << ") : x=" << x << " ; y=" << y << std::endl;
}

void Client::OnAxeChange(unsigned int id,GlWindow::EPeriphAxe axe,double val)
{
	std::cout << "Axe (id #" << id << ") axe " << GlWindow::GetAxeName(axe) << " : val=" << val << std::endl;
}

void Client::OnKeyUp(unsigned int id,int keyCode)
{
	std::cout << "Release (id #" << id << ") : " << keyCode << std::endl;
}

void Client::OnMouseButtonDown(unsigned int id,int b,double x,double y)
{
	std::cout << "Mouse (id #" << id << ") btn #" << b << " pressed : x=" << x << " ; y=" << y << std::endl;
}

void Client::OnMouseButtonUp(unsigned int id,int b,double x,double y)
{
	std::cout << "Mouse (id #" << id << ") btn #" << b << " unpressed : x=" << x << " ; y=" << y << std::endl;
}

void Client::OnButtonDown(unsigned int id,int b)
{
	std::cout << "Button (id #" << id << ") btn #" << b << " pressed" << std::endl;
}

void Client::OnButtonUp(unsigned int id,int b)
{
	std::cout << "Button (id #" << id << ") btn #" << b << " unpressed" << std::endl;
}

void Client::OnJoystickButtonDown(unsigned int id,int b)
{
	std::cout << "Joystick (id #" << id << ") btn #" << b << " pressed" << std::endl;
}

void Client::OnJoystickButtonUp(unsigned int id,int b)
{
	std::cout << "Joystick (id #" << id << ") btn #" << b << " unpressed" << std::endl;
}

void Client::OnGamepadButtonDown(unsigned int id,int b)
{
	std::cout << "Gamepad (id #" << id << ") btn #" << b << " pressed" << std::endl;
}

void Client::OnGamepadButtonUp(unsigned int id,int b)
{
	std::cout << "Gamepad (id #" << id << ") btn #" << b << " unpressed" << std::endl;
}
