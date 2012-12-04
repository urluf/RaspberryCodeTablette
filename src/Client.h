//coding: utf-8
#ifndef _Client_h
	#define _Client_h

#include "GlWindow.h"
#include <time.h>
#include <Utility/3D/CShaderProgram.h>
#include <Utility/3D/CTexture.h>
#include <Utility/3D/CTextureQuad.h>
#include "graphic/DrawSquare.h"
#include "graphic/DrawCircle.h"
#include "graphic/TaskBar.h"

class Client : protected GlWindow
{
private:
	struct SShaders
	{
		SShaders() :
			ShaderVertex(OpenUtility::CShaderFile::EVertexShader,"vertex shader"),
			ShaderFragment(OpenUtility::CShaderFile::EFragmentShader,"fragment shader")
		{
			RenderingShader.AddShaderFile(&ShaderVertex);
			RenderingShader.AddShaderFile(&ShaderFragment);
		}
		OpenUtility::CShaderProgram RenderingShader;
		OpenUtility::CShaderFile ShaderVertex,ShaderFragment;
	};

	struct SVertex
	{
		GLfloat position[3];
		GLfloat normal[3];
	};

	struct STexture
	{
		GLfloat coord[2];
	};

public:
	Client();
	virtual ~Client();
	void Start();

protected:
	void Init();
	void Uninit();
	void PreRender();
	void Render();
	void OnPeripheralAdd(unsigned int id,const char *name,EPeriphType type);
	void OnPeripheralRemove(unsigned int id,const char *name);
	void OnKeyDown(unsigned int id,int keyCode);
	void OnKeyUp(unsigned int id,int keyCode);
	void OnMouseMove(unsigned int id,double x,double y);
	void On6axisChange(unsigned int id,double x,double y,double z,double rx,double ry,double rz);
	void OnWheelChange(unsigned int id,double x,double y);
	void OnHatChange(unsigned int id,int sub,double x,double y);
	void OnTiltChange(unsigned int id,double x,double y);
	void OnAxeChange(unsigned int id,GlWindow::EPeriphAxe axe,double val);
	void OnMouseButtonDown(unsigned int id,int b,double x,double y);
	void OnMouseButtonUp(unsigned int id,int b,double x,double y);
	void OnButtonDown(unsigned int id,int b);
	void OnButtonUp(unsigned int id,int b);
	void OnJoystickButtonDown(unsigned int id,int b);
	void OnJoystickButtonUp(unsigned int id,int b);
	void OnGamepadButtonDown(unsigned int id,int b);
	void OnGamepadButtonUp(unsigned int id,int b);

private:
	timespec DiffTime(timespec start,timespec end);

private:
	struct timespec _debTime;
	GLuint VBOindex;
	GLuint VBOtex;
	unsigned int nbIndexes;
	SShaders *Shaders;
	//CTextureQuad *TexQuad;
	DrawCircle *circle;
	//DrawSquare *square;
	TaskBar *taskBar;
};

#endif
