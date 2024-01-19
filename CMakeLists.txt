cmake_minimum_required(VERSION 3.0.0)
project(Maze VERSION 0.1.0)

add_executable(Maze src/main.cpp)


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(Maze ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )