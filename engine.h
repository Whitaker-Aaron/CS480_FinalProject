#ifndef ENGINE_H
#define ENGINE_H


#include <assert.h>
#include "window.h"
#include "graphics.h"

static void cursorPositionCallBack(GLFWwindow*, double xpos, double ypos);

class Engine
{
public:
    Engine(const char* name, int width, int height);

    ~Engine();
    bool Initialize();
    void Run();
    void ProcessInput();
    unsigned int getDT();
    long long GetCurrentTimeMillis();
    void Display(GLFWwindow*, double);
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    void updateProjectMatrix(double* offset);
    double cursor_x = 0, cursor_y = 0;
    double initial_x = 0, initial_y = 0;
    double mouseScroll = 0;
    double fov = 45;


private:
    // Window related variables
    Window* m_window;
    const char* m_WINDOW_NAME;
    int m_WINDOW_WIDTH;
    int m_WINDOW_HEIGHT;
    bool m_FULLSCREEN;
    
    bool firstClick;
    bool wasClicked;


    glm::vec3 rotVec = { 0.f, 0.f, 0.f };
    float rotAngle = 0;


    Graphics* m_graphics;

    bool m_running;
};

#endif // ENGINE_H


