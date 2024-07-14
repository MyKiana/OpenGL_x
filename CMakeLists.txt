cmake_minimum_required(VERSION 3.27)
project(opengl_s)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/SoftWare/Qt/5.14.2/msvc2017_64")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        OpenGL
        REQUIRED)

add_executable(opengl_s main.cpp
        src/MyOpenGL.cpp
        src/MyOpenGL.h
        src/MyOpenGL.ui
        src/GLTriangle.cpp
        src/GLTriangle.h)
target_link_libraries(opengl_s
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::OpenGL
)

