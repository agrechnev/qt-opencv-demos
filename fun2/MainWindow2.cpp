//
// Created by Oleksiy Grechnyev
//

#include <opencv2/opencv.hpp>

#include "MainWindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
        QWidget(parent) {
    using namespace std;
    using namespace cv;
    setFixedSize(800, 600);

    // Load an image with OpenCV and convert it to QPixmap via QImage
    Mat m = imread("../data/gpig.jpg");
    pixmap.convertFromImage(QImage(m.data, m.cols, m.rows, 3 * m.cols, QImage::Format_BGR888));
    cout << pixmap.width() << "x" << pixmap.height() << endl;

    // Show the pixmap in the window
    imgPane = new QLabel(this);
    imgPane->setPixmap(pixmap);
}

