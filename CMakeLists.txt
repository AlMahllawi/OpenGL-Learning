cmake_minimum_required(VERSION 3.10)
project(OpenGLProject)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("dependencies/glfw")

add_library(glad "dependencies/glad/src/glad.c")
target_include_directories(glad PUBLIC "dependencies/glad/include")

add_executable(OpenGLProject "src/main.cpp" "src/engine/shader.cpp")
target_include_directories(OpenGLProject PUBLIC "dependencies")
target_link_libraries(OpenGLProject PRIVATE glfw glad)
