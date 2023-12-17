#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <vector>
#include "graphics_headers.h"

class Lightsource
{
public:
    Lightsource();
    Lightsource(glm::vec3 pivot);

    ~Lightsource();
    void Update(glm::mat4 model);
    void Render(GLint posAttrib, GLint colAttrib,  GLint lightAttrib);

    glm::mat4 GetModel();
    glm::vec4 getLightColor() { return lightColor; }

    bool InitBuffers();
    void setupVerticies();

private:
    glm::vec3 pivotLocation;
    glm::vec4 lightColor = glm::vec4(.70f, 0.0f, 0.0f, 1.0f);
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    GLuint vao;

    float angle;
};

#endif /* LIGHTSOURCE_H */