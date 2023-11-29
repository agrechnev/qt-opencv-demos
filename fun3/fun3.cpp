//
// Created by Oleksiy Grechnyev
// FUN3: Here I play a video file with Qt, process each frame with OpenCV, and show the result with Qt
// This sort of combines fun1 and fun2

#include <QtWidgets>

#include "MainWindow3.h"

int main(int argc, char **argv) {
    using namespace std;

    QApplication app(argc, argv);

    MainWindow3 win;
    win.show();
    win.play();

    return app.exec();
}