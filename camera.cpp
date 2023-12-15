#include "camera.h"

Camera::Camera()
{

}

Camera::~Camera()
{

}

bool Camera::Initialize(int w, int h)
{
    //--Init the view and projection matrices
    //  if you will be having a moving camera the view matrix will need to more dynamic
    //  ...Like you should update it before you render more dynamic 
    //  for this project having them static will be fine

    view = glm::lookAt(cameraPos, //Eye Position
        cameraFront, //Focus point
        cameraUp); //Positive Y is up




    //view = glm::lookAt(cameraPos, cameraFront + cameraPos, cameraUp);

    projection = glm::perspective(glm::radians((float)fov), //the FoV typically 90 degrees is good which is what this is set to
        float(w) / float(h), //Aspect Ratio, so Circles stay Circular
        0.01f, //Distance to the near plane, normally a small value like this
        100.0f); //Distance to the far plane, 


    Width = w;
    Height = h;

    return true;
}

glm::mat4 Camera::GetProjection()
{
    return projection;
}

glm::mat4 Camera::GetView()
{
    return view;
}

void Camera::updateViewMatrix(int zed, float rotAngle, glm::vec3 rotVec) {


    posZ += zed;
    cameraPos = { posX, posY, posZ };
    cameraFront += rotVec;

    view = glm::lookAt(cameraPos, //Eye Position
        cameraFront, //Focus point
        cameraUp); //Positive Y is up*/


    projection = glm::perspective(glm::radians((float)fov), //the FoV typically 90 degrees is good which is what this is set to
        float(Width) / float(Height), //Aspect Ratio, so Circles stay Circular
        0.01f, //Distance to the near plane, normally a small value like this
        100.0f); //Distance to the far plane,*/

}

void Camera::updateProjectionMatrix(float offset) {

    if (fov >= 1.0f && fov <= 45.0f) {
        fov -= offset;
    }

    if (fov <= 1.0f) {
        fov = 1.0f;
    }

    if (fov >= 45.0f) {
        fov = 45.0f;
    }
}