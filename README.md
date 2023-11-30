# ImguiInitializer

This is a bunch of boilerplate code for using "Dear Imgui" _(GLFW + OpenGL3)_.

## Usage

### Adding to the CMake project

1. Download and add `ImguiInitializer/` folder into your project
    ```text
    YourProject/
    ├─ thirdparty/
    │  └─ ImguiInitializer/
    ├─ CMakeLists.txt
    └─ main.cpp
    ```
2. Add following lines into your `CMakeLists.txt`:
   ```cmake
   add_subdirectory(thirdparty/ImguiInitializer)
   target_link_libraries(${PROJECT_NAME} ImguiInitializer)
   ```

### Using in the code

To use this library in your own project inherit the `ImguiInitializer` class and override
the `Update()` method. This method will be called over and over while the program runs.

After that create an instance of your own class and call `Run()` on it. It's that simple!

```C++
#include "thirdparty/ImguiInitializer/ImguiInitializer.h"

class MyGUI : public ImguiInitializer {
    bool showDemoWindow = true;

    void Update() override {
        if (showDemoWindow) {
            ImGui::ShowDemoWindow(&showDemoWindow);
        }
    }
};

int main() {
    MyGUI myGui;
    myGui.Run();
    
    return 0;
}
```
