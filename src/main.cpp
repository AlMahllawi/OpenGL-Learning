#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "engine/shader.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Project", NULL, NULL);
  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  float triangle1Vertices[] = {
    -0.5, 0.0f, 0.0f,
    -0.5, 0.5, 0.0f,
    0.0f, 0.0f, 0.0f
  };
  float triangle2Vertices[] = {
    0.0f, 0.0f, 0.0f,
    0.5f, 0.5f, 0.0f,
    0.5f, 0.0f, 0.0f
  };

  unsigned int VBO1, VAO1, VBO2, VAO2;
  glGenVertexArrays(1, &VAO1);
  glGenBuffers(1, &VBO1);

  glBindVertexArray(VAO1);
  glBindBuffer(GL_ARRAY_BUFFER, VBO1);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1Vertices),
               triangle1Vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glGenVertexArrays(1, &VAO2);
  glGenBuffers(1, &VBO2);

  glBindVertexArray(VAO2);
  glBindBuffer(GL_ARRAY_BUFFER, VBO2);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangle2Vertices),
               triangle2Vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  Shader ourShader("src/shaders/shader.vs", "src/shaders/shader.fs");

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ourShader.use();
    glBindVertexArray(VAO1);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(VAO2);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
