
#ifndef SKYBOXSHADER_H
#define SKYBOXSHADER_H

#include <vector>

#include "graphics_headers.h"

class Skyboxshader
{
public:
    Skyboxshader();
    ~Skyboxshader();
    bool Initialize();
    void Enable();
    bool AddShader(GLenum ShaderType);
    bool Finalize();
    GLint GetUniformLocation(const char* pUniformName);
    GLint GetAttribLocation(const char* pAttribName);


private:
    GLuint m_shaderProg;
    std::vector<GLuint> m_shaderObjList;
};

#endif  /* SKYBOXSHADER_H */
