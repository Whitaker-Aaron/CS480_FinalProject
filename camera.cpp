#include "camera.h"
#include <glm/gtx/vector_angle.hpp>

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

    for (int i = 0; i < 9; i++) {
        pressed[i] = {false};
    }

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

bool Camera::updateViewMatrix(bool arr[], double xcoord, double ycoord, int zed, float rotAngle, glm::vec3 rotVec) {


    /*posZ += zed;
    cameraPos = { posX, posY, posZ };
    cameraFront += rotVec;*/
    //cameraFront += rotVec;

    for (int i = 0; i < 9; i++) {
        pressed[i] = arr[i];
    }

    if (pressed[0] == true) {

        cameraPos += speed * 10 * cameraFront;
        std::cout << "Up key pressed" << std::endl;

    }

    if (pressed[1] == true) {

        cameraPos += speed * -glm::normalize(glm::cross(cameraFront, cameraUp));
        std::cout << "Left key pressed" << std::endl;

    }

    if (pressed[2] == true) {


        cameraPos += speed * 10 * -cameraFront; 
        std::cout << "Down key pressed" << std::endl;
    }

    if (pressed[3] == true) {

        cameraPos += speed * glm::normalize(glm::cross(cameraFront, cameraUp));
        std::cout << "Right key pressed" << std::endl;

    }

    if (pressed[4] == true) {

        cameraPos += speed * cameraUp;
        std::cout << "Space key pressed" << std::endl;

    }

    if (pressed[5] == true) {

        cameraPos += speed * -cameraUp;
        std::cout << "Left control key pressed" << std::endl;

    }

    if (pressed[6] == true) {

        speed = 0.2f;
        std::cout << "Left shift key pressed" << std::endl;

    }

    else if (pressed[7] == true) {

        speed = 0.1f;
        //std::cout << "Right key pressed" << std::endl;

    }


    if (pressed[8] == true) {

        clicked = true;
        
        std::cout << "Left mouse pressed" << std::endl;
        float xRotation = sensitivity * (float)(ycoord - (Height / 2)) / Height;
        float yRotation = sensitivity * (float)(xcoord - (Width / 2)) / Width;

        glm::vec3 nextCameraFront = glm::rotate(cameraFront, glm::radians(-xRotation), glm::normalize(glm::cross(cameraFront, cameraUp)));
        std::cout << xcoord << std::endl;
        std::cout << ycoord << std::endl;
   


        if (abs(glm::angle(nextCameraFront, cameraUp) - glm::radians(90.0f)) <= glm::radians(85.0f)) {
            
            cameraFront = nextCameraFront;

        }

        cameraFront = glm::rotate(cameraFront, glm::radians(-yRotation), cameraUp);


    }
    else {
        clicked = false;
    }



    view = glm::lookAt(cameraPos, //Eye Position
        cameraFront + cameraPos, //Focus point
        cameraUp); //Positive Y is up*/


    projection = glm::perspective(glm::radians((float)fov), //the FoV typically 90 degrees is good which is what this is set to
        float(Width) / float(Height), //Aspect Ratio, so Circles stay Circular
        0.01f, //Distance to the near plane, normally a small value like this
        100.0f); //Distance to the far plane,*/


    return clicked;
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