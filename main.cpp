
#define STB_IMAGE_IMPLEMENTATION
#include "src/stb_image.h"
#include "src/transaction_module.h"
#include <GLFW/glfw3.h>
#include <iostream>

int main(int argc, char *argv[]) {

  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  GLFWwindow *window =
      glfwCreateWindow(1080, 720, "Finance Tracker", NULL, NULL);

  GLFWimage images[1];
  images[0].pixels = stbi_load("expenseicon.png", &images[0].width,
                               &images[0].height, 0, 4); // rgba channels
  glfwSetWindowIcon(window, 1, images);
  stbi_image_free(images[0].pixels);

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
