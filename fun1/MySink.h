//
// Created by Oleksiy Grechnyev
//

#ifndef QT_OPENCV_DEMOS_MYSINK_H
#define QT_OPENCV_DEMOS_MYSINK_H


#include <QtWidgets>
#include <QtMultimedia>

class MySink: QObject {
    Q_OBJECT
    Q_DISABLE_COPY(MySink)

public:
    explicit MySink(QObject *parent = nullptr);

    QVideoSink *videoSink = nullptr;

public slots:
    void newVideoFrame(const QVideoFrame &frame);
};


#endif //QT_OPENCV_DEMOS_MYSINK_H
