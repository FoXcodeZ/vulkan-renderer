include(FetchContent)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Disable GLFW documentation")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Disable GLFW tests")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Disable GLFW examples")

FetchContent_Declare(
        glfw3
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG d9d6f0f # GLFW 3.5.1
        FIND_PACKAGE_ARGS 3.5.1 CONFIG
)

# GLM
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 8d1fd52 # 1.0.3
        FIND_PACKAGE_ARGS 1.0.3 CONFIG
)

# Slang
FetchContent_Declare(
        slang
        GIT_REPOSITORY https://github.com/shader-slang/slang.git
        GIT_TAG 0fb6b75 # v2026.19
        FIND_PACKAGE_ARGS 2026.19 CONFIG
)

# Vulkan SDK
FetchContent_Declare(
        VulkanHeaders
        GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Headers.git
        GIT_TAG 6802bb4 # 1.4.3
        FIND_PACKAGE_ARGS 1.4.3 CONFIG
)

find_package(Vulkan REQUIRED)

FetchContent_MakeAvailable(
        glfw3
        glm
        slang
        VulkanHeaders
)