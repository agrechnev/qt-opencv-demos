//
// Created by Oleksiy Grechnyev
//
#include <iostream>

#include <opencv2/opencv.hpp>


#include "DwarfPlayer.h"

DwarfPlayer::DwarfPlayer(QObject *parent) :
        QObject(parent) {
    player.setSource(QUrl::fromLocalFile("../data/tvoya.mp4"));
    videoSink = new QVideoSink(this);
    player.setVideoSink(videoSink);
    connect(videoSink, &QVideoSink::videoFrameChanged, this, &DwarfPlayer::newVideoFrame);
}

void DwarfPlayer::newVideoFrame(const QVideoFrame &frame) {
    using namespace std;
    using namespace cv;
    // QVideoFrame is typically in YuV, luckily Qt knows how to convert
    QImage img = frame.toImage().convertToFormat(QImage::Format_BGR888);

    // Now we copy the frame to cv::Mat so that we can process it in OpenCV
    // Note: the data is safely cloned by memcpy
    int rows = img.height(), cols = img.width();
    Mat m(rows, cols, CV_8UC3);
    memcpy(m.data, img.bits(), rows*cols*3);

    // Now that we have an OpenCV image we can process it with OpenCV !
    int w0 = m.cols / 3, h0 = m.rows / 3;
    Mat mCenter(m, Rect2i(w0, h0, w0, h0));
    bitwise_not(mCenter, mCenter);

    // Emit a signal, send the OpenCV image
    newOpenCVFrame(m);
}

void DwarfPlayer::play() {
    player.play();
}
