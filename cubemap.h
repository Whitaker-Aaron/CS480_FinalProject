#pragma once
#include "graphics_headers.h"
#include "Texture.h"
#include <SOIL2/SOIL2.h>

class Cubemap
{

public:
	Cubemap();
	Cubemap(const char* fileName);
	bool loadTexture(const char* texFile);
	GLuint getTextureID() { return m_TextureID; }
	unsigned int loadCubemap();
	void setupVertices();


private:
	GLuint m_TextureID;
	const char* file;
	std::vector<Vertex> Vertices;
	std::vector<unsigned int> Indices;
	bool InitBuffers();
	bool hasTex;

	Texture* m_texture;

	GLuint VB;
	GLuint IB;

	GLuint vao;


	bool initializeTexture();

};