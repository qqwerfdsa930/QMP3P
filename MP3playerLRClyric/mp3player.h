#ifndef MP3PLAYER_H
#define MP3PLAYER_H
#include <QFileDialog>
#include <QMediaPlayer>

class MP3Player
{
public:
    MP3Player();
    ~MP3Player();

public slots:
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
};

#endif // MP3PLAYER_H
