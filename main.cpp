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
    glm::vec3 testVec = {3.13f, 2.12f, 1.34f};
    std::print("testVec({}, {}, {})\n", testVec.x, testVec.y, testVec.z);

    VkApplicationInfo appInfo {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.apiVersion = VK_API_VERSION_1_4;
    appInfo.pApplicationName = "Vulkan Renderer";

    VkInstanceCreateInfo instanceCreateInfo {};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pApplicationInfo = &appInfo;

    VkInstance instance {};
    const VkResult result = vkCreateInstance(&instanceCreateInfo, nullptr, &instance);

    if (result != VK_SUCCESS)
    {
        std::print("Vulkan instance creation failed");
        return -1;
    }
    
    std::print("Vulkan instance created successfully.");

    glfwSetErrorCallback(glfwErrorCallback);

    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);

    if (!glfwInit())
    {
        std::print("glfwInit() failed");
        return 1;
    }

    std::printf("GLFW: %s\n", glfwGetVersionString());

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