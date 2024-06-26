cmake_minimum_required(VERSION 3.10)
project(FinanceTracker VERSION 0.1)

# cpp standard version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the path to the GLFW build directory
set(GLFW_BUILD_DIR ${CMAKE_SOURCE_DIR}/glfw_build)
set(SQLITE3_DIR ${CMAKE_SOURCE_DIR}/sqlite)

add_executable(FinanceTracker main.cpp)

#add SQLite3 source files
add_library(sqlite3 STATIC ${SQLITE3_DIR}/sqlite3.c)

#include directories for SQLite3
target_include_directories(sqlite3 PUBLIC ${SQLITE3_DIR})

# OS-specific configurations
if (WIN32)
  # Windows specific settings
  set(GLFW_INCLUDE_DIR ${GLFW_BUILD_DIR}/include)
  set(GLFW_LIB_DIR ${GLFW_BUILD_DIR}/lib-mingw-w64)

  # Include GLFW headers
  target_include_directories(FinanceTracker PRIVATE ${GLFW_INCLUDE_DIR})

  # Link GLFW libraries
  target_link_libraries(FinanceTracker PRIVATE ${GLFW_LIB_DIR}/libglfw3.a)
  target_link_libraries(FinanceTracker PRIVATE opengl32)

  target_link_libraries(FinanceTracker PRIVATE sqlite3)
elseif (UNIX)

  # Linux specific settings
  add_subdirectory(${GLFW_BUILD_DIR})

  # Include GLFW headers
  target_include_directories(FinanceTracker PRIVATE ${GLFW_BUILD_DIR}/include)


  # Link GLFW libraries
  target_link_libraries(FinanceTracker PRIVATE glfw)
  # find_package(OpenGL REQUIRED)
  # target_link_libraries(FinanceTracker PRIVATE ${OPENGL_LIBRARIES})
endif()
