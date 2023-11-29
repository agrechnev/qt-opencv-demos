//
// Created by Oleksiy Grechnyev
//
// FUN2: Here I load a single image with OpenCV and display it with Qt

#include <QtWidgets>

#include "MainWindow2.h"

int main(int argc, char **argv) {
    using namespace std;

    QApplication app(argc, argv);
    qInfo() << "QT_VERSION (COMPILE TIME) = " << QT_VERSION_STR;
    qInfo() << "QT_VERSION (RUN TIME) = " << qVersion();

    MainWindow2 mainWindow;
    mainWindow.show();

    return app.exec();
}