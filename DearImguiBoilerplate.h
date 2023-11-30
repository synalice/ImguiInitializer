#ifndef ARKANA_GUI_H
#define ARKANA_GUI_H

#include "imgui.h"
#include "GLFW/glfw3.h"
#include <iostream>

class DearImguiBoilerplate {
public:
    DearImguiBoilerplate();

    virtual ~DearImguiBoilerplate();

    void Run();

    virtual void Update() = 0;

private:
    GLFWwindow *window;

    static void glfwErrorCallback(int error, const char *description) {
        std::cerr << "GLFW Error " << error << ": " << description << std::endl;
    }

protected:
    ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};

#endif //ARKANA_GUI_H
