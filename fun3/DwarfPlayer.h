//
// Created by Oleksiy Grechnyev
//

#ifndef QT_OPENCV_DEMOS_DWARFPLAYER_H
#define QT_OPENCV_DEMOS_DWARFPLAYER_H


#include <QtWidgets>
#include <QtMultimedia>

#include <opencv2/core.hpp>

/// Play a media file using Qt and emit a signal with RGB images
class DwarfPlayer : public QObject {
Q_OBJECT

    Q_DISABLE_COPY(DwarfPlayer)

public:
    explicit DwarfPlayer(QObject *parent = nullptr);

    void play();

signals:
    void newOpenCVFrame(const cv::Mat &frame);

private slots:
    void newVideoFrame(const QVideoFrame &);

private:
    QMediaPlayer player;
    QVideoSink *videoSink = nullptr;
};


#endif //QT_OPENCV_DEMOS_DWARFPLAYER_H
