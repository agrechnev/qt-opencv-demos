cmake_minimum_required(VERSION 3.10)
project(fun3)

add_executable(${PROJECT_NAME} fun3.cpp
        MainWindow3.h MainWindow3.cpp
        DwarfPlayer.cpp
        DwarfPlayer.h
)
target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::Multimedia  ${OpenCV_LIBRARIES})
