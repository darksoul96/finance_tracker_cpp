cmake_minimum_required(VERSION 3.10)
project(FinanceTracker VERSION 0.1)

# cpp standard version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the path to the GLFW build directory
set(GLFW_BUILD_DIR ${CMAKE_SOURCE_DIR}/glfw_build)


# Add GLFW to the project
add_subdirectory(${GLFW_BUILD_DIR} glfw)

add_executable(FinanceTracker main.cpp)

# Include GLFW headers
target_include_directories(FinanceTracker PRIVATE ${GLFW_BUILD_DIR}/include)

# Link GLFW libraries
target_link_libraries(FinanceTracker PRIVATE glfw)

