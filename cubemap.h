#pragma once
#include "graphics_headers.h"
#include "Texture.h"
#include <SOIL2/SOIL2.h>

class Cubemap
{

public:
	Cubemap();
	GLuint getTextureID() { return m_TextureID; }
	bool InitBuffers();
	void Render(GLint posAttribLoc);

private:
	GLuint m_TextureID;
	const char* file;
	std::vector<Vertex> Vertices;
	std::vector<unsigned int> Indices;

	void setupVertices();
	
	
	bool hasTex;

	const char* facesCubemap[6] = {
		"FinalProjectAssets\\bkg\\blue\\bkg1_right.png",
		"FinalProjectAssets\\bkg\\blue\\bkg1_left.png",
		"FinalProjectAssets\\bkg\\blue\\bkg1_top.png",
		"FinalProjectAssets\\bkg\\blue\\bkg1_bot.png",
		"FinalProjectAssets\\bkg\\blue\\bkg1_front.png",
		"FinalProjectAssets\\bkg\\blue\\bkg1_back.png"
	};


	Texture* m_texture;

	GLuint VB;
	GLuint IB;

	GLuint vao;


};