#ifndef LIGHTSHADER_H
#define LIGHTSHADER_H

#include <vector>

#include "graphics_headers.h"

class Lightshader
{
public:
    Lightshader();
    ~Lightshader();
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

#endif  /* LIGHTSHADER_H */