#ifndef TIMER_H
#define TIMER_H

#include <QMediaPlayer>
#include <QString>

class Timer
{
public:
    struct Time_data
    {
        unsigned int min;
        unsigned int sec;
    };

    Timer();
    ~Timer();

    void show(QMediaPlayer::State);
    void reset();
    QString getQTimer();

private:
    Time_data tData;
    QString Qtimer;
};

#endif // TIMER_H
