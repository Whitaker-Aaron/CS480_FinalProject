#pragma once
#include "graphics_headers.h"
#include <SOIL2/SOIL2.h>

class Texture
{

public:
	Texture();
	Texture(const char* fileName);
	Texture(const char* faces[]);
	bool loadTexture(const char* texFile);
	bool loadCubemapTexture(const char* faces[]);
	GLuint getTextureID() { return m_TextureID; }

private:
	GLuint m_TextureID;
	//GLuint m_TextureIDFaces[6];
	

	bool initializeTexture();
	bool initializeCubemapTexture();

};
