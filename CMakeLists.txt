cmake_minimum_required(VERSION 3.10)
project(qt-opencv-demos)
set(CMAKE_CXX_STANDARD 20)

file(COPY data DESTINATION .)

#Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS Widgets Multimedia REQUIRED)


# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(fun1)
add_subdirectory(fun2)
add_subdirectory(fun3)
