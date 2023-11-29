//
// Created by Oleksiy Grechnyev
//

#ifndef QT_OPENCV_DEMOS_MAINWINDOW2_H
#define QT_OPENCV_DEMOS_MAINWINDOW2_H

#include <QtWidgets>


class MainWindow2 : public QWidget {
Q_OBJECT
    Q_DISABLE_COPY(MainWindow2)

public:
    explicit MainWindow2(QWidget *parent = nullptr);

private:
    QPixmap pixmap;
    QLabel *imgPane = nullptr;
};


#endif //QT_OPENCV_DEMOS_MAINWINDOW2_H
