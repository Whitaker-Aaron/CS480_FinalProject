#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <stack>
using namespace std;

#include "graphics_headers.h"
#include "pyramid.h"
#include "camera.h"
#include "shader.h"
#include "lightShader.h"
#include "skyboxShader.h"
#include "object.h"
#include "lightsource.h"
#include "cubemap.h"
#include "sphere.h"
#include "mesh.h"

#define numVBOs 2;
#define numIBs 2;


class Graphics
{
public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void HierarchicalUpdate2(double dt);
    void Render();

    Camera* getCamera() { return m_camera; }

private:
    std::string ErrorString(GLenum error);

    bool collectShPrLocs();
    void ComputeTransforms(double dt, std::vector<float> speed, std::vector<float> dist,
        std::vector<float> rotSpeed, glm::vec3 rotVector, std::vector<float> scale,
        glm::mat4& tmat, glm::mat4& rmat, glm::mat4& smat);

    stack<glm::mat4> modelStack;

    Camera* m_camera;
    Shader* m_shader;
    Lightshader* m_lightshader;
    Skyboxshader* m_skyboxshader;
    

    //For Default Shader
    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;
    GLint m_positionAttrib;
    GLint m_colorAttrib;
    GLint m_tcAttrib;
    GLint m_hasTexture;
    GLint m_lightColor;
    GLint m_lightPos;
    GLint m_camPos;

    //For Light Shader
    GLint m_projectionMatrix2;
    GLint m_viewMatrix2;
    GLint m_modelMatrix2;
    GLint m_positionAttrib2;
    GLint m_colorAttrib2;
    GLint m_tcAttrib2;
    GLint m_hasTexture2;
    GLint m_lightColor2;

    //For Skybox Shader
    GLint m_projectionMatrix3;
    GLint m_viewMatrix3;
    GLint m_modelMatrix3;
    GLint m_positionAttrib3;

    glm::vec4 light;
    glm::vec3 lightPosition = { 0.0f, 0.0f, 0.0f };


    Pyramid* m_pyramid;

    Sphere* m_sphere;
    Sphere* m_sphere2;
    Sphere* m_sphere3;
    Sphere* m_sphere4;
    Sphere* m_sphere5;
    Sphere* m_sphere6;
    Sphere* m_sphere7;
    Sphere* m_sphere8;
    Sphere* m_sphere9;
    Sphere* m_sphere10;
    Sphere* m_sphere11;
    Sphere* m_sphere12;
    Sphere* m_sphere13;
    Sphere* m_sphere14;
    Sphere* m_sphere15;
    Sphere* m_sphere16;
    Sphere* m_sphere17;


    Mesh* m_mesh;
    Mesh* m_mesh2;

    Lightsource* m_lightsource;
    Cubemap* m_cubemap;

};

#endif /* GRAPHICS_H */
