
#include "cubemap.h"

Cubemap::Cubemap(const char* fileName) {

	file = fileName;
	m_texture = new Texture(fileName);
	if (m_texture)
		hasTex = true;
	else
		hasTex = false;

	//loadTexture(fileName);
	//initializeTexture();
}

Cubemap::Cubemap() {
	m_TextureID = -1;
	printf("No Texture Data Provided.");
}

bool Cubemap::loadTexture(const char* texFile) {
	/*m_TextureID = SOIL_load_OGL_texture(texFile, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (!m_TextureID) {
		printf("Failed: Could not open texture file!\n");
		return false;
	}
	std::cout << "Texture loaded" << std::endl;
	return true;*/
	return true;
}

bool Cubemap::initializeTexture() {

	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);





	return true;
}

unsigned int Cubemap::loadCubemap() {







	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);


	return 0;



}

void Cubemap::setupVertices() {

	Vertices = {
		{{ -1.0f,  -1.0f, 1.0f}, {0.f, 0.f, 0.f}, {1.f, 0.f}},
		{{ 1.0f,  -1.0f, 1.0f}, {0.f, 0.f, 0.f}, {1.f, 0.f}},
		{{ 1.0f,  -1.0f, -1.0f}, {0.f, 0.f, 0.f}, {1.f, 0.f}},
		{{ -1.0f,  -1.0f, -1.0f}, {0.f, 0.f, 0.f}, {1.f, 0.f}},
		{{ -1.0f,  1.0f, 1.0f}, {0.f, 0.f, 0.f}, {1.f, 0.f}},
		{{ 1.0f,  1.0f, 1.0f}, {0.f, 0.f, 0.f}, {1.f, 0.f}},
		{{ 1.0f,  1.0f, -1.0f}, {0.f, 0.f, 0.f}, {1.f, 0.f}},
		{{ -1.0f,  1.0f, -1.0f}, {0.f, 0.f, 0.f}, {1.f, 0.f}},

		
	};

	Indices = {
	  1, 2, 6,
	  6, 5, 1,
	  0, 4, 7,
	  7, 3, 0,
	  4, 5, 6,
	  6, 7, 4,
	  0, 3, 2,
	  2, 1, 0,
	  0, 1, 5,
	  5, 4, 0,
	  3, 7, 6,
	  6, 2, 3
	};

}

bool Cubemap::InitBuffers() {

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &VB);
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &IB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);

	return false;

	//glVertexAttribPointer(posAttribLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);


}