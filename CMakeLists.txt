cmake_minimum_required(VERSION 3.28)
project(VulkanRenderer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/dependencies.cmake")

add_executable(VulkanRenderer main.cpp)

target_link_libraries(VulkanRenderer
        PRIVATE
        glfw
        glm::glm
        Vulkan::Vulkan
)
