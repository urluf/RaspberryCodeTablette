/*
 * SShaders.h
 *
 *  Created on: 6 déc. 2012
 *      Author: developpeur
 */
#ifndef _SSHADERS_H
#define _SSHADERS_H

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

#endif

