#ifndef IMGUI_BOILERPLATE_INITIALIZER_H
#define IMGUI_BOILERPLATE_INITIALIZER_H

#include <GLFW/glfw3.h>
#include <imgui.h>

class ImguiInitializer {
public:
    ImguiInitializer();

    virtual ~ImguiInitializer();

    void Run();

    virtual void Update() = 0;

private:
    GLFWwindow *window;

protected:
    ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};

#endif// IMGUI_BOILERPLATE_INITIALIZER_H
