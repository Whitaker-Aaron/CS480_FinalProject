#include "engine.h"

#include "glm/ext.hpp"

Engine::Engine(const char* name, int width, int height)
{
    m_WINDOW_NAME = name;
    m_WINDOW_WIDTH = width;
    m_WINDOW_HEIGHT = height;

}


Engine::~Engine()
{
    delete m_window;
    delete m_graphics;
    m_window = NULL;
    m_graphics = NULL;
}

bool Engine::Initialize()
{
    // Start a window
    m_window = new Window(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT);
    if (!m_window->Initialize())
    {
        printf("The window failed to initialize.\n");
        return false;
    }

    // Start the graphics
    m_graphics = new Graphics();
    if (!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
    {
        printf("The graphics failed to initialize.\n");
        return false;
    }

    glfwSetCursorPosCallback(m_window->getWindow(), cursorPositionCallBack);


    // No errors
    return true;
}

void Engine::Run()
{
    m_running = true;

    while (!glfwWindowShouldClose(m_window->getWindow()))
    {
        ProcessInput();
        Display(m_window->getWindow(), glfwGetTime());
        glfwPollEvents();
    }
    m_running = false;

}

void Engine::ProcessInput()
{
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window->getWindow(), true);

    //std::cout << "Xpos: " << cursor_x << std::endl;
    //std::cout << "Ypos: " << cursor_y << std::endl;



    glfwGetCursorPos(m_window->getWindow(), &cursor_x, &cursor_y);
    glfwSetScrollCallback(m_window->getWindow(), scroll_callback);


    // Update camera animation here.
    if (cursor_x != initial_x || cursor_y != initial_y) {

        if (cursor_x > initial_x) {
            //rotAngle = 0.1;
            rotVec = { 1.f, 0.f, 0.f };
        }

        if (cursor_x < initial_x) {
            //rotAngle = -0.1;
            rotVec = { -1.f, 0.f, 0.f };
        }

        if (cursor_y > initial_y) {
            //rotAngle = 0.1;
            rotVec = { 0.f, 1.f, 0.f };
        }

        if (cursor_y < initial_y) {
            //rotAngle = -0.1;
            rotVec = { 0.f, -1.f, 0.f };
        }

        initial_x = cursor_x;
        initial_y = cursor_y;


    }

    else {
        rotAngle = 0.0f;
        rotVec = { 0.f, 0.f, 0.f };
    }




    //if(cursor_x > )


    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window->getWindow(), true);

    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_W) == GLFW_RELEASE &&
        glfwGetKey(m_window->getWindow(), GLFW_KEY_A) == GLFW_RELEASE &&
        glfwGetKey(m_window->getWindow(), GLFW_KEY_S) == GLFW_RELEASE &&
        glfwGetKey(m_window->getWindow(), GLFW_KEY_D) == GLFW_RELEASE) {

        m_graphics->getCamera()->updateViewMatrix(0, rotAngle, rotVec);
    }


    //Pressing W moves the camera forward (+1 on the Z-axis) and pressing S moves the camera backwards (-1 on the Z-axis).
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_W) == GLFW_PRESS)
        m_graphics->getCamera()->updateViewMatrix(1, rotAngle, rotVec);

    //if (glfwGetKey(m_window->getWindow(), GLFW_KEY_A) == GLFW_PRESS)
    //   m_graphics->getCamera()->updateViewMatrix(glm::vec3(-0.1f, 0.0f, 0.0f), rotAngle, rotVec);

    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_S) == GLFW_PRESS)
        m_graphics->getCamera()->updateViewMatrix(-1, rotAngle, rotVec);

    //if (glfwGetKey(m_window->getWindow(), GLFW_KEY_D) == GLFW_PRESS)
    //   m_graphics->getCamera()->updateViewMatrix(glm::vec3(0.1f, 0.0f, 0.0f), rotAngle, rotVec);


}

void Engine::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{

    glfwGetCursorPos(window, &xpos, &ypos);
    std::cout << "Position: (" << xpos << ":" << ypos << ")";
}

unsigned int Engine::getDT()
{
    //long long TimeNowMillis = GetCurrentTimeMillis();
    //assert(TimeNowMillis >= m_currentTimeMillis);
    //unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
    //m_currentTimeMillis = TimeNowMillis;
    //return DeltaTimeMillis;
    return glfwGetTime();
}

long long Engine::GetCurrentTimeMillis()
{
    //timeval t;
    //gettimeofday(&t, NULL);
    //long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
    //return ret;
    return (long long)glfwGetTime();
}

void Engine::Display(GLFWwindow* window, double time) {

    m_graphics->Render();
    m_window->Swap();
    m_graphics->HierarchicalUpdate2(time);
}

static void cursorPositionCallBack(GLFWwindow* window, double xpos, double ypos) {
    //cout << xpos << " " << ypos << endl;
}

void Engine::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {

    //m_graphics->getCamera()->updateProjectionMatrix(yoffset);

}