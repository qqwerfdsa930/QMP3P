#ifndef MP3PLAYER_H
#define MP3PLAYER_H
#include <QFileDialog>
#include <QMediaPlayer>
#include <thread>
#include "timer.h"

class MP3Player
{
public:
    MP3Player(){   player->setVolume(100);    }

    ~MP3Player(){   delete player;   }

    void MusicPlay();
    void MusicStop();
    QString getFileName();
    QChar getFileName(int i);
    void setFileName(QString qStr);
    int getFileNameLength();
    QMediaPlayer::Error getError();
    QMediaPlayer::State getStat();

private:
    QString FileName;
    QMediaPlayer* player = new QMediaPlayer();
    Timer t;
};

#endif // MP3PLAYER_H
