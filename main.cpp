#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <print>
#include <fmt/printf.h>

static void glfwErrorCallback(int error, const char* description)
{
    std::printf("GLFW error %d: %s", error, description);
}

int main()
{
    glfwSetErrorCallback(glfwErrorCallback);

    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);

    if (!glfwInit())
    {
        std::print("glfwInit() failed");
        return 1;
    }

    std::printf("GLFW: %s", glfwGetVersionString());

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow* window = glfwCreateWindow(
        1024,
        768,
        "Vulkan Renderer",
        nullptr,
        nullptr
    );

    if (!window)
    {
        std::print("glfwCreateWindow() failed");
        glfwTerminate();
        return 1;
    }

    glfwShowWindow(window);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}