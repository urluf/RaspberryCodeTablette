#include "CTextureQuad.h"
#include <stddef.h>

CTextureQuad::CTextureQuad(const char *srcImg,double maxW,double maxH, double z)
{
	Texture=CTexture::LoadTexture(srcImg);
	HasAllocatedTex=true;
	CalcSize(maxW,maxH);
	this->z = z;
}

CTextureQuad::CTextureQuad(CTexture *tex,double maxW,double maxH) :
	HasAllocatedTex(false),
	Texture(tex)
{
	CalcSize(maxW,maxH);
}

CTextureQuad::CTextureQuad(const CTextureQuad &obj) :
	HasAllocatedTex(false),
	Texture(obj.Texture),
	w(obj.w),
	h(obj.h)
{
}

CTextureQuad& CTextureQuad::operator=(const CTextureQuad &obj)
{
	HasAllocatedTex=false;
	Texture=obj.Texture;
	w=obj.w;
	h=obj.h;
	return(*this);
}

CTextureQuad::~CTextureQuad()
{
	if (HasAllocatedTex)
		delete Texture;
	glDeleteBuffers(1,&VBObuffer);
}

void CTextureQuad::CalcSize(double maxW,double maxH)
{

	w=maxW;
	h=maxH;

	SVertex VertexArray[4];

	double tx=double(Texture->GetW())/Texture->GetWT();
	double ty=double(Texture->GetH())/Texture->GetHT();

	SetVertex(VertexArray[0],-w,h,0,ty);
	SetVertex(VertexArray[1],-w,-h,0,0);
	SetVertex(VertexArray[2],w,-h,tx,0);
	SetVertex(VertexArray[3],w,h,tx,ty);

	glGenBuffers(1,&VBObuffer);
	glBindBuffer(GL_ARRAY_BUFFER,VBObuffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof(VertexArray),VertexArray,GL_STATIC_DRAW);
}

void CTextureQuad::SetVertex(SVertex &vertex,double posX,double posY,double texX,double texY)
{
	vertex.position[0]=posX;
	vertex.position[1]=posY;
	vertex.position[2]= this->z;
	vertex.normal[0]=0;
	vertex.normal[1]=0;
	vertex.normal[2]=0;
	vertex.texcoord[0]=texX;
	vertex.texcoord[1]=texY;

}

void CTextureQuad::AttachAttribToData(GLuint vPos,GLuint vNorm,GLuint vTex, GLuint texID)
{
	glBindBuffer(GL_ARRAY_BUFFER,VBObuffer);
	glVertexAttribPointer(vPos,3,GL_FLOAT,GL_FALSE,sizeof(SVertex),(void*)offsetof(SVertex,position));
	glVertexAttribPointer(vNorm,3,GL_FLOAT,GL_FALSE,sizeof(SVertex),(void*)offsetof(SVertex,normal));
	glVertexAttribPointer(vTex,2,GL_FLOAT,GL_FALSE,sizeof(SVertex),(void*)offsetof(SVertex,texcoord));
	glEnableVertexAttribArray(vPos);
	glEnableVertexAttribArray(vNorm);
	glEnableVertexAttribArray(vTex);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,Texture->GetId());
	glUniform1i(texID,0);
}

void CTextureQuad::Draw()
{
	// Set the sampler texture unit to 0
	glDrawArrays(GL_TRIANGLE_FAN,0,4);
	glBindBuffer(GL_ARRAY_BUFFER,0);
}
