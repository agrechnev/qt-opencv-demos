//
// Created by Oleksiy Grechnyev
//

#include <iostream>

#include "MySink.h"

#include <opencv2/opencv.hpp>


MySink::MySink(QObject *parent) :
        QObject(parent) {
    // MySink contains a QVideoSink
    videoSink = new QVideoSink(this);
    connect(videoSink, SIGNAL( videoFrameChanged(const QVideoFrame &)), this, SLOT(newVideoFrame(const QVideoFrame &)));
}

void MySink::newVideoFrame(const QVideoFrame &frame) {
    using namespace std;
    using namespace cv;

    // QVideoFrame is typically in YuV, luckily Qt knows how to convert
    QImage img = frame.toImage().convertToFormat(QImage::Format_BGR888);

    // Now we copy the frame to cv::Mat and can process it in OpenCV
    int rows = img.height(), cols = img.width();
    Mat m(rows, cols, CV_8UC3);
    memcpy(m.data, img.bits(), rows*cols*3);

    // When using Qt, the imshow() window could look weird (on Ubuntu 23.10) or even fail on some platforms
    imshow("video", m);
    if (27 == waitKey(1))
        exit(0);

    // But in any case, you can use the cv::Mat in any way you like
//    imwrite("frame.png", m);

}

