
#include "Texture.h"

Texture::Texture(const char* fileName) {

	loadTexture(fileName);
	initializeTexture();
}

Texture::Texture(const char* faces[]) {
	loadCubemapTexture(faces);
	initializeCubemapTexture();

}


Texture::Texture() {
	m_TextureID = -1;
	printf("No Texture Data Provided.");
}

bool Texture::loadTexture(const char* texFile) {
	m_TextureID = SOIL_load_OGL_texture(texFile, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (!m_TextureID) {
		printf("Failed: Could not open texture file!\n");
		return false;
	}
	std::cout << "Texture loaded" << std::endl;
	return true;
}

bool Texture::loadCubemapTexture(const char* faces[]) {

	m_TextureID = SOIL_load_OGL_cubemap(faces[0], faces[1], faces[2], faces[3], faces[4], faces[5], SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (!m_TextureID) {
		printf("Failed: Could not open cubemap texture files!\n");
		return false;
	}
	std::cout << "Cubemap textures loaded" << std::endl;
	return true;
}



bool Texture::initializeTexture() {

	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}

bool Texture::initializeCubemapTexture() {
	
	
	//unsigned int cubemapTexture; 
	//glGenTextures(1, &cubemapTexture);
	
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);


	return true;
}
