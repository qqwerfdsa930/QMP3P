#include "mp3player.h"

QString MP3Player::getFileName()
{
    return FileName;
}

void MP3Player::setFileName(QString qStr)
{
    FileName = qStr;
}

int MP3Player::getFileNameLength()
{
    return FileName.length();
}

void MP3Player::MusicPlay()
{
    player->setMedia(QUrl::fromLocalFile(FileName));
    player->play();
}

void MP3Player::MusicStop()
{
    player->stop();
}

QMediaPlayer::Error MP3Player::getError()
{
    return player->error();
}

QMediaPlayer::State MP3Player::getStat()
{
    return player->state();
}
