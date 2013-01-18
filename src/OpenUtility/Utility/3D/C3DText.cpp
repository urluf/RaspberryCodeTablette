#include "C3DText.h"

OpenUtility::C3DText::C3DText(const OpenUtility::CFontLoader *loader) :
	CFontLoader::CFontEngine(loader),
	VertexTab(NULL)
{
	CommonInit();
}

OpenUtility::C3DText::C3DText(const C3DText &obj) :
	CFontLoader::CFontEngine(obj),
	VertexTab(NULL)
{
	CommonInit();
	SetText(obj.Text,obj.CurrentHAlign,obj.CurrentVAlign);
}

void OpenUtility::C3DText::CommonInit()
{
	glGenBuffers(1,&VBObuffer);
}

OpenUtility::C3DText::~C3DText()
{
	glDeleteBuffers(1,&VBObuffer);
	delete[] VertexTab;
}

OpenUtility::C3DText& OpenUtility::C3DText::operator=(const C3DText &obj)
{
	return(*this);
}

void OpenUtility::C3DText::SetText(const char *text,EHAlign hAlign,EVAlign vAlign)
{
	CurrentHAlign=hAlign;
	CurrentVAlign=vAlign;
	UpdateText(text);
}

void OpenUtility::C3DText::UpdateText(const char *text)
{
	unsigned int i;
	int currentX,currentY;
	double size=FontLoader->GetSize();
	const CTexture* texture=FontLoader->GetFontTexture();

	Text=text;
	delete[] VertexTab;
	VertexTab=new SVertex[Text.GetSize()*4];

	TotalX=0;
	MinY=0;
	MaxY=0;
	for (i=0;i<Text.GetSize();i++)
	{
		const CFontLoader::SFontChar *fontData=FontLoader->GetCharData(text[i]);
		TotalX+=fontData->Advance;
		if (MinY>(currentY=fontData->BearingY-fontData->texH)) MinY=currentY;
		if (MaxY<(currentY=fontData->BearingY)) MaxY=currentY;
	}

	currentX=0;
	for (i=0;i<Text.GetSize();i++)
	{
		const CFontLoader::SFontChar *fontData=FontLoader->GetCharData(text[i]);
		double x,y;

		switch(CurrentHAlign)
		{
		case EHAlignLeft:x=currentX;break;
		case EHAlignCenter:x=currentX-TotalX/2.0;break;
		case EHAlignRight:x=currentX-TotalX;break;
		default:x=0;
		}
		x=(x+fontData->BearingX)/size;
		currentX+=fontData->Advance;

		switch(CurrentVAlign)
		{
		case EVAlignBottom:y=-MinY;break;
		case EVAlignBaseligne:y=0;break;
		case EVAlignMiddle:y=-((MaxY-MinY)/2.0+MinY);break;
		case EVAlignTop:y=-MaxY;break;
		default:y=0;
		}
		y=(y-fontData->texH+fontData->BearingY)/size;

		SetVertex(VertexTab[i*4],x,y,
								fontData->texX/double(texture->GetWT()),(fontData->texY+fontData->texH)/double(texture->GetHT()));
		SetVertex(VertexTab[i*4+1],x+fontData->texW/size,y,
								(fontData->texX+fontData->texW)/double(texture->GetWT()),(fontData->texY+fontData->texH)/double(texture->GetHT()));
		SetVertex(VertexTab[i*4+2],x,y+fontData->texH/size,
								fontData->texX/double(texture->GetWT()),fontData->texY/double(texture->GetHT()));
		SetVertex(VertexTab[i*4+3],x+fontData->texW/size,y+fontData->texH/size,
								(fontData->texX+fontData->texW)/double(texture->GetWT()),fontData->texY/double(texture->GetHT()));
	}

	glBindBuffer(GL_ARRAY_BUFFER,VBObuffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof(SVertex)*4*Text.GetSize(),VertexTab,GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,0);
}

void OpenUtility::C3DText::SetAlignement(EHAlign hAlign,EVAlign vAlign)
{
	if (VertexTab)
	{
		bool isUpdated=false;

		if (CurrentHAlign!=hAlign)
		{
			double x1,x2;

			switch(hAlign)
			{
			case EHAlignLeft:x1=0;break;
			case EHAlignCenter:x1=-TotalX/2.0;break;
			case EHAlignRight:x1=-TotalX;break;
			default:x1=0;
			}

			switch(CurrentHAlign)
			{
			case EHAlignLeft:x2=0;break;
			case EHAlignCenter:x2=-TotalX/2.0;break;
			case EHAlignRight:x2=-TotalX;break;
			default:x2=0;
			}
			x1=(x1-x2)/FontLoader->GetSize();

			for (unsigned int i=0;i<Text.GetSize()*4;i++)
				VertexTab[i].position[0]+=x1;

			isUpdated=true;
			CurrentHAlign=hAlign;
		}

		if (CurrentVAlign!=vAlign)
		{
			double y1,y2;

			switch(vAlign)
			{
			case EVAlignBottom:y1=-MinY;break;
			case EVAlignBaseligne:y1=0;break;
			case EVAlignMiddle:y1=-((MaxY-MinY)/2.0+MinY);break;
			case EVAlignTop:y1=-MaxY;break;
			default:y1=0;
			}

			switch(CurrentVAlign)
			{
			case EVAlignBottom:y2=-MinY;break;
			case EVAlignBaseligne:y2=0;break;
			case EVAlignMiddle:y2=-((MaxY-MinY)/2.0+MinY);break;
			case EVAlignTop:y2=-MaxY;break;
			default:y2=0;
			}
			y1=(y1-y2)/FontLoader->GetSize();

			for (unsigned int i=0;i<Text.GetSize()*4;i++)
				VertexTab[i].position[1]+=y1;

			isUpdated=true;
			CurrentVAlign=vAlign;
		}

		if (isUpdated)
		{
			glBindBuffer(GL_ARRAY_BUFFER,VBObuffer);
			glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(SVertex)*4*Text.GetSize(),VertexTab);
			glBindBuffer(GL_ARRAY_BUFFER,0);
		}
	}
}

void OpenUtility::C3DText::AttachAttribToData(GLuint vPos,GLuint vNorm,GLuint vTex)
{
	glBindBuffer(GL_ARRAY_BUFFER,VBObuffer);
	glVertexAttribPointer(vPos,3,GL_FLOAT,GL_FALSE,sizeof(SVertex),(void*)offsetof(SVertex,position));
	glVertexAttribPointer(vNorm,3,GL_FLOAT,GL_FALSE,sizeof(SVertex),(void*)offsetof(SVertex,normal));
	glVertexAttribPointer(vTex,2,GL_FLOAT,GL_FALSE,sizeof(SVertex),(void*)offsetof(SVertex,texcoord));
	glEnableVertexAttribArray(vPos);
	glEnableVertexAttribArray(vNorm);
	glEnableVertexAttribArray(vTex);
	glBindTexture(GL_TEXTURE_2D,FontLoader->GetFontTexture()->GetId());
}

void OpenUtility::C3DText::Draw()
{
	for (unsigned int i=0;i<Text.GetSize();i++)
		glDrawArrays(GL_TRIANGLE_STRIP,i*4,4);
}

void OpenUtility::C3DText::SetVertex(SVertex &vertex,double posX,double posY,double texX,double texY)
{
	vertex.position[0]=posX;
	vertex.position[1]=posY;
	vertex.position[2]=0;
	vertex.normal[0]=0;
	vertex.normal[1]=0;
	vertex.normal[2]=1.0;
	vertex.texcoord[0]=texX;
	vertex.texcoord[1]=texY;
}
