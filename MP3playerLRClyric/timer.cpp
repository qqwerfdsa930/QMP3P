#include "timer.h"

Timer::Timer()
{
    reset();
}

Timer::~Timer()
{

}

void Timer::show(QMediaPlayer::State state)
{
    if(state == QMediaPlayer::State::PlayingState)
    {
        ++tData.sec;
        if(tData.sec == 60)
        {
            ++tData.min;
            tData.sec = 0;
        }

        if(tData.min < 10)
        {
            Qtimer = "0";
            Qtimer += QString::number(tData.min);
        }
        else
            Qtimer = QString::number(tData.min);

        Qtimer += ":";

        if(tData.sec < 10)
        {
            Qtimer += "0";
        }
        Qtimer += QString::number(tData.sec);
    }
    else if(state == QMediaPlayer::State::StoppedState)
    {
        reset();
    }
}

void Timer::reset()
{
    tData.min = 0;
    tData.sec = 0;
    Qtimer = "00:00";
}

QString Timer::getQTimer()
{
    return Qtimer;
}
