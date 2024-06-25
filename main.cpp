
#include <GLFW/glfw3.h>
#include <iostream>

int main (int argc, char *argv[]) {
  // Initialize GLFW
  if (!glfwInit()) {
      std::cerr << "Failed to initialize GLFW" << std::endl;
      return -1;
  } 

  GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

  if (!window) {
    glfwTerminate();
    return -1;
  }

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();


  return 0;
}
