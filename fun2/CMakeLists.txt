cmake_minimum_required(VERSION 3.10)
project(fun2)

add_executable(${PROJECT_NAME} fun2.cpp
        MainWindow2.cpp
        MainWindow2.h
)
target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::Multimedia  ${OpenCV_LIBRARIES})
