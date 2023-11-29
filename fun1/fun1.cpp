// By Oleksiy Grechnyev, 2023
// FUN1: Here I play a video file with  QMediaPlayer
// And break it into individual frames using QVideoSink
// This is strictly Qt6, Qt5 had a rather different media API!

#include <iostream>

#include <QtWidgets>
#include <QtMultimedia>

#include "MySink.h"

// Change to your video file
const char *VIDEO_FILE = "../data/tvoya.mp4";

int main(int argc, char **argv) {
    using namespace std;

    QApplication app(argc, argv);
    qInfo() << "QT_VERSION (COMPILE TIME) = " << QT_VERSION_STR;
    qInfo() << "QT_VERSION (RUN TIME) = " << qVersion();

    QUrl url = QUrl::fromLocalFile(VIDEO_FILE);

    // Qt logger can print Qt objects directly, cout can't
    cout << "URL =" << url.toDisplayString().toStdString() << endl;
//    qInfo() << "URL =" << url;

    // Create player+sink and play
    QMediaPlayer player;
    player.setSource(url);
    MySink mySink;
    player.setVideoSink(mySink.videoSink);

    player.play();

    return app.exec();
}