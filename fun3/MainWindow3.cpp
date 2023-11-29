//
// Created by Oleksiy Grechnyev
//
#include <iostream>

#include <opencv2/opencv.hpp>

#include "MainWindow3.h"

MainWindow3::MainWindow3(QWidget *parent):
    QWidget(parent) {
    setFixedSize(800, 600);
    imgPane = new QLabel(this);


    // Connect player signal to this window's slot
    connect(&dwarfPlayer, &DwarfPlayer::newOpenCVFrame, this, &MainWindow3::newOpenCVFrame);
}

void MainWindow3::play() {
    dwarfPlayer.play();
}

void MainWindow3::newOpenCVFrame(const cv::Mat &frameCV) {
    using namespace std;
    using namespace cv;

    // Display frameCV (an opencv image) with Qt
    pixmap.convertFromImage(QImage(frameCV.data, frameCV.cols, frameCV.rows, 3 * frameCV.cols, QImage::Format_BGR888));
    // Important: without such manual resize the image pane will not auto-resize !
    if (imgPane->width() != pixmap.width() || imgPane->height() != pixmap.height())
        imgPane->setFixedSize(pixmap.width(), pixmap.height());
    imgPane->setPixmap(pixmap);
}
