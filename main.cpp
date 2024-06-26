
#include "src/database_module.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <sqlite3.h>

int main(int argc, char *argv[]) {

  sqlite3 *db;
  int rc = sqlite3_open("finance.db", &db);

  if (rc) {
    std::cerr << "Failed to open database: " << sqlite3_errmsg(db);
    return -1;
  }

  DB::CreateTransactionsTable(db);
  DB::SelectTransactions(db);

  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  GLFWwindow *window =
      glfwCreateWindow(1080, 720, "Finance Tracker", NULL, NULL);

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

  sqlite3_close(db);

  return 0;
}
