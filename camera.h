#ifndef CAMERA_H
#define CAMERA_H

#include "graphics_headers.h"

class Camera
{
public:
    Camera();
    ~Camera();
    bool Initialize(int w, int h);
    glm::mat4 GetProjection();
    glm::mat4 GetView();

    void updateViewMatrix(bool arr[], double xcoord, double ycoord, int zed, float rotAngle, glm::vec3 rotVec);
    void updateProjectionMatrix(float offset);

private:

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;


    float speed = 0.01f;
    float sensitivity = 1.0f;

    double posX = 0.0;
    double posY = 0.0;
    double posZ = -16.0;

    int Width, Height;

    double fov = 45;

    glm::vec3 cameraPos = { 0.0f, 0.0f, 0.1f };
    glm::vec3 cameraFront = { 0.0f, 0.0f, -0.1f };
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::mat4 projection;
    glm::mat4 view;

    bool pressed[9];

};

#endif /* CAMERA_H */