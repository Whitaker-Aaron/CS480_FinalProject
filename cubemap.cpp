
#include "cubemap.h"

Cubemap::Cubemap() {

	
	m_texture = new Texture(facesCubemap);
	if (m_texture)
		hasTex = true;
	else
		hasTex = false;

	//loadTexture(fileName);
	//initializeTexture();
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

void Cubemap::Render(GLint posAttribLoc)
{

	glBindVertexArray(vao);

	// Enable vertex attibute arrays for each vertex attrib
	glEnableVertexAttribArray(posAttribLoc);

	// Bind your VBO
	glBindBuffer(GL_ARRAY_BUFFER, VB);

	// Set vertex attribute pointers to the load correct data
	glVertexAttribPointer(posAttribLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	// Bind your Element Array
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

	// Render
	glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

	// Disable vertex arrays
	glDisableVertexAttribArray(posAttribLoc);
}