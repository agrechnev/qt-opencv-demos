cmake_minimum_required(VERSION 3.10)
project(fun1)

add_executable(${PROJECT_NAME} fun1.cpp
        MySink.cpp
        MySink.h
)
target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::Multimedia  ${OpenCV_LIBRARIES})
