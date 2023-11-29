//
// Created by Oleksiy Grechnyev
//

#ifndef QT_OPENCV_DEMOS_MAINWINDOW3_H
#define QT_OPENCV_DEMOS_MAINWINDOW3_H

#include <QtWidgets>

#include "DwarfPlayer.h"

class MainWindow3 : public QWidget {
Q_OBJECT
    Q_DISABLE_COPY(MainWindow3)

public:
    explicit MainWindow3(QWidget *parent = nullptr);
    void play();

private slots:
    void newOpenCVFrame(const cv::Mat &frameCV);

private:
    DwarfPlayer dwarfPlayer;
    QPixmap pixmap;
    QLabel *imgPane = nullptr;
};


#endif //QT_OPENCV_DEMOS_MAINWINDOW3_H
